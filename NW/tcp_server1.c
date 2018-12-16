#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define RCVBUF 32



int main(int argc , char *argv[])
{

	int sock;
	struct sockaddr_in eserveraddr ;
	unsigned int port;
	char * servIP;
	char * echostr;
	char echobuf[32];
	unsigned int strlen;
	int bytercvd, totalbyte;
	unsigned short serport;

	servIP = argv[1];
//	echostr =argv[2];

	serport = atoi(argv[2]);



	sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

	printf("sock %d\n", sock);
	
	memset(&eserveraddr, 0, sizeof(eserveraddr));
	eserveraddr.sin_family = AF_INET;
	eserveraddr.sin_addr.s_addr = inet_addr(servIP);
	eserveraddr.sin_port = htons(serport);

	bind(sock, (struct sockaddr*)&eserveraddr, sizeof(eserveraddr));
	
	printf("sock bind %d\n", sock);
	
	listen(sock,1);

	printf("sock listen %d\n", sock);

	accept(sock, (struct sockaddr*)&eserveraddr, sizeof(eserveraddr));
	
//	connect(sock,(struct sockaddr*)&eserveraddr,sizeof(eserveraddr));

	while(1 )
	{
		
		printf("sock %d   while \n", sock);
		recv(sock,echobuf,31,0);
		echobuf[32] = '\0';
		printf("data rcvd %s",echobuf);

		send(sock, "ACK",3,0);
	}

	return 0;


}
