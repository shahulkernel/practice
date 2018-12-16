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
	echostr =argv[2];

	serport = atoi(argv[3]);


	sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	
	memset(&eserveraddr, 0, sizeof(eserveraddr));
	eserveraddr.sin_family = AF_INET;
	eserveraddr.sin_addr.s_addr = inet_addr(servIP);
	eserveraddr.sin_port = htons(serport);

	connect(sock,(struct sockaddr*)&eserveraddr,sizeof(eserveraddr));

	send(sock, "hai",3,0);
	recv(sock,echobuf,31,0);

	echobuf[32] = '\0';

	printf("data rcvd %s",echobuf);

	return 0;


}
