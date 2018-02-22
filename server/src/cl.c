#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8081

/*struct in_addr{
	uint32_t s_addr;
};*/
/*struct sockaddr_in{
	sa_family_t sin_family; // address family
	uint16_t sin_port; // port number
	struct in_addr sin_addr;  // IP address
};*/


int main(int argc, char const *argv[])
{
	struct sockaddr_in address;
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	int sock_fd = 0;
	char buffer[1024] = {0};
	char *text = "hello from client";
	int value_read;
	socklen_t addresslength = sizeof(server_addr);

	if((sock_fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))< 0){
		printf("socket creation error\n");
		return -1;
	}

	//memset(&server_addr, '0', sizeof(server_addr));
	server_addr.sin_addr.s_addr = inet_addr("10.0.0.111");
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons( 8081 );

//	if(inet_pton(AF_INET, "10.0.0.111", &server_addr.sin_addr) < 0)
//	    {
//	        printf("\nInvalid address/ Address not supported \n");
//	        return -1;
//	    }


	if(connect(sock_fd, (struct sockaddr*)&server_addr, addresslength) < 0){
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


