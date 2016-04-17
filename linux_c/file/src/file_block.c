#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

// block read
int main(){
    size_t len;
    char buffer[100] = {'\0'};
    while((len = read(STDIN_FILENO, buffer, sizeof(buffer)))>0){
        if(write(STDOUT_FILENO, buffer, len) < 0){
            fprintf(stderr, "write error:%s\n", strerror(errno));
            exit(1);
        }
    }
    
    return 0;
}
