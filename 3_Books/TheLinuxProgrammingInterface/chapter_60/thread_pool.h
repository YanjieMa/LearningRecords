#include "condition.h"


typedef struct task{
	void (*run)(void *args);	//函数
	void *args;					//函数参数
	struct task *next;			//下一个任务
}task_t;

typedef struct threadpool{
	condition_t ready;
	task_t *first;
	task_t *last;
	int run_threads;
	int idle_threads;
	int max_threads;
	int quit_flag;
}threadpool_t;
