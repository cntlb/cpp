#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *args[]){
    pid_t pid = fork();
    if(pid<0){
        fprintf(stderr, "fork error:%s\n", strerror(errno));
        exit(1);
    }else if(pid > 0)//parent process
    {
        while(1){
            sleep(1);
        }
        printf("parent pid:%d, ppid:%d,  child pid:%d\n",getpid(),getppid(),pid);
    }else{
       printf("child pid:%d, ppid:%d\n",getpid(),getppid());
       exit(1);
    }
    //另开终端 ps -ef|grep a.out查看 <defunct>即为僵死进程
    //无法通过kill -9 僵死进程pid杀死， 可以通过杀死父进程一起杀死
    return 0;
}
