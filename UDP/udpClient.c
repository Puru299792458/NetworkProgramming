#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(){
    int sockfd=socket(AF_INET, SOCK_DGRAM, 0);;
    char buffer[1024];
    char *hello = "C lient says hello";
    struct sockaddr_in servaddr;
    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5000);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    int n, len;
    sendto(sockfd, (const char *)hello, strlen(hello),0,(const struct sockaddr *) &servaddr,sizeof(servaddr));
    printf("Hello message sent.\n");
    n = recvfrom(sockfd, (char *)buffer, MAXLINE,0, (struct sockaddr *) &servaddr,&len);
    buffer[n] = '\0';
    printf("Server : %s\n", buffer);
    close(sockfd);
    return 0;
}
