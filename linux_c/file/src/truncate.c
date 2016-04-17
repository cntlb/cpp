#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

long getSize(char*pathname){
    struct stat st;
    if(lstat(pathname, &st) < 0){
        fprintf(stderr, "stat error: %s\n", strerror(errno));
        exit(1);
    }
    return st.st_size;
}

int main(int argc, char *args[]){
     if(argc < 3){
        fprintf(stderr, "useage error: %s\n", strerror(errno));
        printf("useage:%s <pathname> <size in byte>\n", args[0]);
        printf("eg: %s ~/1.txt 20 \n", args[0]);
        exit(1);
    }
    
    long size = getSize(args[1]);
    printf("file %s with size:%ld bytes.\n", args[1], size);
    long arg_size = atol(args[2]);
    size = arg_size<size?arg_size:size;
    
    if(truncate(args[1], size)<0){
        fprintf(stderr, "trun file %s failed: %s\n", args[1], strerror(errno));
        exit(1);
    }

    printf("cate first %ld bytes success.\n", size);
    
    return 0;
}
