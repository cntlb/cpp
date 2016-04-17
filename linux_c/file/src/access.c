#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *args[]){
     if(argc < 2){
        fprintf(stderr, "useage error: %s\n", strerror(errno));
        printf("useage:%s <pathname>\n", args[0]);
        exit(1);
    }
    
    if(access(args[1], F_OK) == 0){
        printf("file %s exists!\n",args[1]);
    }else{
        printf("file %s not exists!\n",args[1]);
        exit(1);
    }
    
    if(access(args[1], R_OK) == 0){
        printf("file %s can read\n",args[1]);
    }else{
        printf("file %s can't read!\n",args[1]);
    }
    
    return 0;
}
