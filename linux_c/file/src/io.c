#include "io.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#define BUF_LEN 1024

void copy(int fd_in, int fd_out){
    char buffer[BUF_LEN] = {'\0'};
    size_t len;
    while((len = read(fd_in, buffer, BUF_LEN)) != 0){
        if(write(fd_out, buffer, len) != len){
            fprintf(stderr, "write error:%s\n", strerror(errno));
            exit(1);
        }
    }
}

int set_flag(int fd, int flag){
    int org_flag = fcntl(fd, F_GETFL);
    org_flag |= flag;
    if(fcntl(fd, F_SETFL, org_flag)<0){
        return -1;
    }
    return org_flag;
}

int lock_reg(int fd, int cmd, short l_type, short l_whence, off_t l_start, off_t l_len){
    struct flock lock;
    memset(&lock, 0, sizeof(struct flock));
    lock.l_type = l_type;
    lock.l_whence = l_whence;
    lock.l_start = l_start;
    lock.l_len = l_len;
    
    return fcntl(fd, cmd, &lock);
}
