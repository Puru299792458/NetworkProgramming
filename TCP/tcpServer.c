#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<fcntl.h>

int main(){
	int welcome,newSoc,n;
	char buffer[1024],fname[20];
	struct sockaddr_in addr;
	welcome=socket(PF_INET,SOCK_STREAM,0);
	addr.sin_family=AF_INET;
	addr.sin_port=htons(5001);
	addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	bind(welcome,(struct sockaddr *)&addr,sizeof(addr));
	printf("\nServer Online\n");
	listen(welcome,5);
	newSoc=accept(welcome,NULL,NULL);
	recv(newSoc,fname,50,0);
	printf("\nRequesting file name:%s\n",fname);
	FILE *fp=fopen(fname,"r");
	if(fp==NULL){
		send(newSoc,"\nFile not found\n",15,0);
	}else{
		while((fscanf(fp,"%s",buffer))!=EOF){
			send(newSoc,buffer,strlen(buffer),0);
		}
	}
	printf("\nRequest sent\n");
	fclose(fp);
	return 0;
}
