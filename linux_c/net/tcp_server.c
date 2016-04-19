#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>



int main(int argc, char* args[]){
    
    //socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketfd < 0){
        fprintf(stderr, "Socket error:%s\n\a", strerror(errno));
        exit(1);
    }
    //bind
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(args[1]));
    addr.sin_addr.s_addr = INADDR_ANY;
    
    if(bind(socketfd, (struct sockaddr*)&addr, sizeof(addr)) < 0){
        fprintf(stderr, "Socket bind error:%s\n\a", strerror(errno));
        exit(1);
    }
    
    //listen
    if(listen(socketfd, 10) < 0){
        fprintf(stderr, "Socket listen error:%s\n\a", strerror(errno));
        exit(1);
    }
    
    //accept
    struct sockaddr_in client;
    int lenth = sizeof(client);
    int fd = accept(socketfd, (struct sockaddr*)&client, &lenth);
    if(fd<0){
        fprintf(stderr, "Socket accept error:%s\n\a", strerror(errno));
        exit(1); 
    }
    
    //read/write
    //print client ip and prot
    char buffer[16];
    inet_ntop(AF_INET, &client.sin_addr.s_addr, buffer, sizeof(client));
    unsigned short port = ntohs(client.sin_port);
    printf("client ip:%s port:%d", buffer, port);
    
    //send message to client
    const char* str = "Hello Server under Ubuntu OS!";
    write(fd, str, strlen(str));
    close(fd);
    
    return 0;
}

