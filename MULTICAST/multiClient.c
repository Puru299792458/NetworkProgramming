#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
	struct sockaddr_in localSock;
	struct ip_mreq group;
	int sd,reuse=1;
	char databuf[1024];
	sd=socket(AF_INET,SOCK_DGRAM,0);
	setsockopt(sd,SOL_SOCKET,SO_REUSEADDR,(char*)&reuse,sizeof(reuse));
	printf("Setting SO_REuseaddr..ok\n");
	localSock.sin_family=AF_INET;
	localSock.sin_port=htons(4321);
	localSock.sin_addr.s_addr=INADDR_ANY;
	bind(sd,(struct sockaddr*)&localSock,sizeof(localSock));
	printf("Binding datagram socket...ok\n");
	group.imr_multiaddr.s_addr=inet_addr("226.1.1.1");
	group.imr_interface.s_addr=INADDR_ANY;
	setsockopt(sd,IPPROTO_IP,IP_ADD_MEMBERSHIP,(char*)&group,sizeof(group));
	printf("Adding multicast group...ok\n");
	read(sd,databuf,1024);
	printf("Reading datagram message..ok\n");
	printf("The message from multicast server:%s\n",databuf);
	return 0;
}
