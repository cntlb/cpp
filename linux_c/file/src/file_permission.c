#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *args[]){
    if(argc < 2){
        fprintf(stderr, "useage error: %s\n", strerror(errno));
        printf("useage:%s <pathname>\n", args[0]);
        exit(1);
    }
    
    struct stat st;
    if(stat(args[1], &st) < 0){
        fprintf(stderr, "stat error: %s\n", strerror(errno));
        exit(1);
    }
    
    mode_t mode = st.st_mode;
    printf(" ");
    //user
    if(mode & S_IRUSR){
        printf("r");
    }else{
        printf("-");
    }
    if(mode & S_IWUSR){
        printf("w");
    }else{
        printf("-");
    }
    if(mode & S_IXUSR){
        printf("x");
    }else{
        printf("-");
    }
    
    //group
    if(mode & S_IRGRP){
        printf("r");
    }else{
        printf("-");
    }
    if(mode & S_IWGRP){
        printf("w");
    }else{
        printf("-");
    }
    if(mode & S_IXGRP){
        printf("x");
    }else{
        printf("-");
    }
    
    //other
        if(mode & S_IROTH){
        printf("r");
    }else{
        printf("-");
    }
    if(mode & S_IWOTH){
        printf("w");
    }else{
        printf("-");
    }
    if(mode & S_IXOTH){
        printf("x");
    }else{
        printf("-");
    }
    printf("\n");
    return 0;
}

