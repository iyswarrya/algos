
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include<unistd.h>
#define PORT 8083

int main(int argc, char const *argv[])
{
	struct sockaddr_in address;
	int serversock_fd;
	int addresslength = sizeof(address);
	int newsock_fd;
	int value_read;
	char buffer[1024] = {0};
	address.sin_family = AF_INET;
	address.sin_port = htons(8083);
	address.sin_addr.s_addr = INADDR_ANY;

	if((serversock_fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))< 0){
		printf("socket creation error\n");
		return -1;
	}

	if(bind(serversock_fd,(struct sockaddr*)&address,sizeof(address)) < 0){
		printf("binding error\n");
		return -1;
	}

	if(listen(serversock_fd,5) < 0){
		printf("listening error\n");
		return -1;
	}else{
		printf("listening\n");
	}

	if((newsock_fd = accept(serversock_fd, (struct sockaddr *)&address, (socklen_t *)&addresslength)) <0){
		printf("accept error\n");
		return -1;
	}
	while(1)
	{
		value_read = read(newsock_fd,buffer,1024);
		if(value_read == -1){
			printf("error in receiving\n");
			exit(1);
		}
		printf("Message from client is: %s", buffer);
		printf("\nEnter data to be sent to client:");
		fgets(buffer,100,stdin);
		if(strncmp(buffer,"end",3)==0)
			break;

		if( send(newsock_fd,buffer,100,0) < 0){
			printf("error in sending\n");
			exit(1);
		}


	}

	close(newsock_fd);
	exit(0);
	return 0;


}
