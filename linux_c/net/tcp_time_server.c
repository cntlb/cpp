#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <time.h>

int sockfd;

void do_service(fd)
{
    long t = time(0);
    char *s = ctime(&t);
    write(fd,s,strlen(s));
}
void out_client(struct sockaddr_in clientaddr)
{
    char buffer[16];
    inet_ntop(AF_INET,&clientaddr.sin_addr.s_addr,buffer,sizeof(clientaddr));
    unsigned short port = ntohs(clientaddr.sin_port);
    printf("client ip:%s (%d)\n",buffer,port);
}


int main(int argc,char *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr,"usage: %s port\n",argv[0]);
        exit(1);
    }

    //1.create socket
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd < 0)
    {
        fprintf(stderr,"socket: %s\n",strerror(errno));
        exit(1);
    }

    //set ip and port
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family = AF_INET;//ipv4
	//本机字节序转化为网络字节序
	//atoi, atol, atoll - convert a string to an integer
    addr.sin_port = htons(atoi(argv[1]));
	//使用本地回环地址
    addr.sin_addr.s_addr = INADDR_ANY; 

    //2. bind ip and port
    int len = sizeof(addr);
    if(bind(sockfd,(struct sockaddr*)&addr,len) < 0)
    {
        fprintf(stderr,"bind: %s\n",strerror(errno));
        exit(1);
    }

    //3. begin to listen
	//listen第二个参数是监听的个数
    if(listen(sockfd,10) < 0)
    {
        fprintf(stderr,"listen: %s\n",strerror(errno));
        exit(1);
    }

	//4. read or write
    while(1)
    {
        struct sockaddr_in clientaddr;
        int c_len = sizeof(clientaddr);
        int fd = accept(sockfd,(struct sockaddr*)&clientaddr,&c_len);
        if(fd < 0)
        {
            fprintf(stderr,"accept: %s\n",strerror(errno));
            continue;
        }
        out_client(clientaddr);
        do_service(fd);
        close(fd);

    }
    return 0;
}
