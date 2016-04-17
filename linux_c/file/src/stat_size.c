#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

//test stat() function
int main(int argc, char *args[]){
    
    if(argc < 2){
        fprintf(stderr, "useage error: %s\n", strerror(errno));
        printf("useage:%s <pathname>\n", args[0]);
        exit(1);
    }
    
    struct stat st;
    if(lstat(args[1], &st) < 0){
        fprintf(stderr, "stat error: %s\n", strerror(errno));
        exit(1);
    }
    
    printf("%s size is %ld bytes\n", args[1], st.st_size);
   
    return 0;
}

