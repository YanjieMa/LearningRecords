
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <time.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <fcntl.h>




struct myevent{
	int fd;
	int event;
	void *arg;
	void (*call_back)(int fd, int enent, void *arg);
	int status;
	long active;
};




int mysend(int sockfd, char *buf, size_t len)
{
	unsigned int sended = 0;//已经发送的数据
	int thissended;//本次发送的数据
	
	if(len <= 0){
		return sended;
	}

	while(sended < len){
		do{
			thissended = send(sockfd, buf, len-sended, 0);
		}while(thissended < 0 && errno == EINTR);//发送时遇到终端 重新发送
		if(thissended < 0){
			return sended;
		}
		sended += thissended;
		buf += thissended;
	}

	return len;
}

int myrecv(int sockfd, char *buf, size_t len)
{
	unsigned int readed = 0;
	int thisreaded = 0;

	if(len <= 0){
		return readed;
	}

	while(readed < len){
		do{
			thisreaded = recv(sockfd, buf, len - readed, 0);
		}while(thisreaded <0 && errno == EINTR);
		if(thisreaded < 0){
			return readed;
		}else if(thisreaded == 0){
			return readed;
		}
		readed += thisreaded;
		buf += thisreaded;		
	}
}
