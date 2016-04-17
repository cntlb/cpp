#include "io.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *args[]){
    if(argc < 2){
        printf("useage:cat pathname\n");
        exit(1);
    }
    
    int fd_in = open(args[1], O_RDONLY);
    if(fd_in < 0){
        printf("open file %s error:%s\n", args[1], strerror(errno));
        exit(1);
    }

    copy(fd_in, STDOUT_FILENO);
    close(fd_in);
    return 0;
}
