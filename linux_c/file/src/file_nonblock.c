#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// non block read
int main(){
    //set non block flag
    set_flag(STDIN_FILENO, O_NONBLOCK);
    size_t len;
    char buffer[100] = {'\0'};
    sleep(3);
    while((len = read(STDIN_FILENO, buffer, sizeof(buffer))) != -1){
        if(len == 0){
            printf("finished\n");
        }else if(len > 0){
            if(write(STDOUT_FILENO, buffer, len) != len){
                fprintf(stderr, "write error:%s\n", strerror(errno));
                exit(1);
            }
        }
    }
    
    
    return 0;
}
