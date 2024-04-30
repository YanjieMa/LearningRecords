#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>

#include "thread_pool.h"


void *thread_routine(void *arg);

void threadpool_init(threadpool_t *pool, int max_threads)
{
	condition_init(&pool->ready);
	pool->first = NULL;
	pool->last = NULL;	
	pool->run_threads = 0;
	pool->idle_threads = 0;
	pool->max_threads = max_threads;
	pool->quit_flag = 0;
}

void threadpool_add_task(threadpool_t *pool, void (*run)(void *arg), void *arg)
{
	task_t *newtask = (task_t *)malloc(sizeof(task_t));
	newtask->run = run;
	newtask->args = arg;
	newtask->next = NULL;
	
	condition_lock(&pool->ready);

	if(pool->first == NULL){
		pool->first = newtask;
	}else{
		pool->last->next = newtask;
	}
	pool->last = newtask;

	if(pool->idle_threads > 0){
		condition_signal(&pool->ready);
	}else if(pool->run_threads < pool->max_threads){
		pthread_t tid;
		pthread_create(&tid, NULL, thread_routine, pool);
		pool->run_threads++;
	}else{
		printf("thread pool is full,add task failed\n");
	}
	
	condition_unlock(&pool->ready);
}

void *thread_routine(void *arg)
{
	struct timespec abstime;
	int timeout;

	threadpool_t * pool = (threadpool_t *)arg;
	
	printf("thread %d begin run,max pool size:%d\n", (int)pthread_self(), pool->max_threads);
	
	while(1){
		timeout = 0;
		condition_lock(&pool->ready);
		pool->idle_threads++;
		while(pool->first==NULL && !pool->quit_flag){
			printf("thread %d is waiting, run thread:%d\n",(int)pthread_self(),pool->run_threads);
			clock_gettime(CLOCK_REALTIME, &abstime);
			abstime.tv_sec += 10;
			int status = condition_timedwait(&pool->ready, &abstime);
			if(status == ETIMEDOUT){
				timeout = 1;
				break;
			}
		}

		pool->idle_threads--;

		if(pool->first != NULL){
			task_t *t = pool->first;
			pool->first = t->next;
			condition_unlock(&pool->ready);		
			t->run(t->args);
			free(t);
			condition_lock(&pool->ready);
		}
		if(pool->quit_flag && pool->first == NULL){
			pool->run_threads--;
			if(pool->run_threads == 0){
				condition_signal(&pool->ready);
			}	
			condition_unlock(&pool->ready);
			break;
		}
		if(timeout){
			pool->run_threads--;
			condition_unlock(&pool->ready);
			break;
		}
		condition_unlock(&pool->ready);
	}	
	printf("thread %d end, run threads:%d\n",(int)pthread_self(),pool->run_threads);
	return NULL;
}

void threadpool_destroy(threadpool_t *pool)
{
	if(pool->quit_flag){
		return;
	}
	
	condition_lock(&pool->ready);
	pool->quit_flag = 1;
	if(pool->run_threads > 0){
		if(pool->idle_threads > 0){
			condition_broadcast(&pool->ready);
		}

		while(pool->run_threads){
			condition_wait(&pool->ready);
		}
	}
	condition_unlock(&pool->ready);
	condition_destroy(&pool->ready);
}


