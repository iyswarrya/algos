
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#define PORT 8083

int main(int argc, char const *argv[])
{
	struct sockaddr_in address;
	struct sockaddr_in server_addr;
	int sock_fd = 0;
	char buffer[1024] = {0};
	int value_read;
	//socklen_t addresslength = sizeof(server_addr);

	if((sock_fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))< 0){
		printf("socket creation error\n");
		return -1;
	}


	server_addr.sin_addr.s_addr = inet_addr("10.0.0.111");
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons( 8083);


	if(connect(sock_fd,(struct sockaddr*)&server_addr,sizeof(server_addr)) < 0){
		printf("connection error\n");
		return -1;

	}else{
		printf("connected");
	}

	while(1)
	{
		printf("\nEnter data to be sent to server:");
		fgets(buffer,100,stdin);
		if(strncmp(buffer,"end",3)==0)
			break;
		if( send(sock_fd,buffer,100,0) < 0){
			printf("error in sending\n");
			exit(1);
		}
		value_read = read(sock_fd,buffer,1024);
		if(value_read == -1){
			printf("error in receiving\n");
			exit(1);
		}
		printf("Message from client is: %s", buffer);
	}
	close(sock_fd);
	exit(0);

	return 0;
}
