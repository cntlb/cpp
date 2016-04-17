#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
/*
       void *mmap(void *addr, size_t length, int prot, int flags,
                  int fd, off_t offset);
       int munmap(void *addr, size_t length);

*/
int main(int argc, char *args[]){
    //存储映射
    int fd = open("./1.txt", O_RDWR);
    char *buffer = NULL;
    size_t len = 10;
    
    //返回存储映射区
    buffer = (char*)mmap(buffer, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0L);
    if(buffer == MAP_FAILED){
        fprintf(stderr, "map error: %s\n", strerror(errno));
        exit(1);
    }
    
    //打印到标准输出设备
    int i = 0;
    for(; i<len; i++){
        if(write(STDOUT_FILENO, &buffer[i],1) != 1){
            fprintf(stderr, "write error: %s\n", strerror(errno));
            exit(1);
        }
    }
    //更改存储映射区内容将直接修改源文件， 因此map可以实现文件读写的功能
    buffer[2] = 'a';
    munmap(buffer, len);
    printf("\n");
    return 0;
}
