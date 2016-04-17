#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]){
    //获取环境表
    extern char**environ;
    int i = 0;
    char* env;
    while((env = environ[i]) != NULL){
        printf("%s\n", env);
        i++;
    }
    
    printf("===============================\n");
    //操作环境
    env = getenv("myhome");
    printf("myhome = %s\n", env);
    
    setenv("myhome","hello world", 0);
    
    env = getenv("myhome");
    printf("myhome = %s\n", env);
    return 0;
}
