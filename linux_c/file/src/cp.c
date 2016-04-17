#include "io.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *args[]){
    if(argc < 3){
        printf("useage:cp from to\n");
        exit(1);
    }
    
    int fd_in = open(args[1], O_RDONLY);
    if(fd_in < 0){
        printf("open file %s error:%s\n", args[1], strerror(errno));
        exit(1);
    }
    
    int fd_out = open(args[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fd_in < 0){
        printf("open/create file %s error:%s\n", args[2], strerror(errno));
        exit(1);
    }
    
    copy(fd_in, fd_out);
    close(fd_in);
    close(fd_out);
    return 0;
}
