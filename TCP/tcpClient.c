#include<stdio.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int n,soc;
	char buffer[1024],fname[20];
	struct sockaddr_in addr;
	soc=socket(PF_INET,SOCK_STREAM,0);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(5001);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	while(connect(soc,(struct sockaddr*)&addr,sizeof(addr)));
	printf("\nClient connected to the server\n");
	printf("Enter Filename\n");
	scanf("%s",fname);
	send(soc,fname,sizeof(fname),0);
	while((n=recv(soc,buffer,sizeof(buffer),0))>0)
		printf("%s\n",buffer);
	return 0;
}
	
