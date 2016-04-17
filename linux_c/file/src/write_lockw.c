#include "io.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *args[]){
    if(argc < 3){
        fprintf(stderr, "useage error: %s\n", strerror(errno));
        printf("useage:%s <pathname> append_content\n", args[0]);
        exit(1);
    }
    
    //使用文件锁实现O_APPEND功能
    int fd = open(args[1], O_WRONLY);
    WRITE_LOCKW(fd, SEEK_SET, 0L, 0L);
    lseek(fd, 0L, SEEK_END);

    //观察效果， 每次写一个字符
    size_t c = strlen(args[2]);
    int i = 0;
    for(; i<c; i++){
        if(write(fd, &args[2][i], 1) != 1){
            fprintf(stderr, "write error:%s\n", strerror(errno));
            exit(1);
        }
        printf("%d(pid) write:%c\n", getpid(), args[2][i]);
        sleep(1);
    }

    close(fd);
    UNLOCK(fd, SEEK_SET, 0L, 0L);
    printf("%d write finished\n", getpid());
    return 0;
}
