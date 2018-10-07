#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
	struct sockaddr_in groupSock;
	int sd;
	sd=socket(AF_INET,SOCK_DGRAM,0);
	printf("\nCreating sock ok\n");
	groupSock.sin_family=AF_INET;
	groupSock.sin_addr.s_addr=inet_addr("226.1.1.1");
	groupSock.sin_port=htons(4321);
	printf("Setting the local interface...ok\n");
	sendto(sd,"Hi THis is multicast mesg",27,0,(struct sockaddr*)&groupSock,sizeof(groupSock));
	printf("Sending datagram message...ok\n");
	return 0;
	
}
