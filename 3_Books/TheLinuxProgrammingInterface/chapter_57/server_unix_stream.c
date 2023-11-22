#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <errno.h>
#include <sys/un.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	int lfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(lfd < 0){
		perror("socket error");
		return -1;
	}
	// 防治存在这个文件导致 bind 失败	
//	if(unlink(argv[1]) < 0){
//		perror("unliunk error");
//		return -1;
//	}
	char *p = "xyz";

	struct sockaddr_un server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sun_family = AF_UNIX;
	strncpy(&server_addr.sun_path[1], p, sizeof(server_addr.sun_path)-2);
	
	if(bind(lfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_un)) < 0){
		perror("bind error");
		return -1;
	}
	if(listen(lfd,3) < 0){
		perror("listen error");
		return -1;
	}

	struct sockaddr_un client_addr;
	int client_addr_len = sizeof(struct sockaddr_un);
	for(;;){

		char * w_buf = "wait connect ...\n";
		write(0,w_buf, strlen(w_buf));	
		
		int cfd = accept(lfd, (struct sockaddr *)&client_addr, &client_addr_len);
		if(cfd < 0){
			perror("accept error");
			break;
		}	
		
		int read_len;
		char buf[1024];
		memset(buf, 0, sizeof(buf));
		printf("info:\n");
		while((read_len = read(cfd, buf, sizeof(buf))) > 0){
			if(write(STDOUT_FILENO, buf, read_len) < 0){
				perror("write error");
				break;
			}
			send(cfd, buf, read_len, 0);
			memset(buf, 0, sizeof(buf));
			printf("info:\n");
		}

		if(read_len < 0){
			perror("read error");
			break;
		}
		close(cfd);
	}

	if(unlink(argv[1]) < 0){
		perror("ulink error");
		return -1;
	}
	close(lfd);

	return 0;
}
