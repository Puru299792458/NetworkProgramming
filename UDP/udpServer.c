#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main() {
    int sockfd=socket(AF_INET,SOCK_DGRAM, 0);
    char buffer[1024];
    char *hello = "Server says hi";
    struct sockaddr_in servaddr,cliaddr;
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(5000);
    bind(sockfd, (const struct sockaddr *)&servaddr,sizeof(servaddr));
    int len=sizeof(cliaddr), n;
    n = recvfrom(sockfd, (char *)buffer,MAXLINE, 0,(struct sockaddr *) &cliaddr,&len);
    buffer[n] = '\0';
    printf("Client : %s\n", buffer);
    sendto(sockfd, (const char *)hello, strlen(hello),0,(const struct sockaddr *) &cliaddr,len);
    printf("Hi message sent.\n");
    close(sockfd);
    return 0;
}
