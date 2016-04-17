#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *args[]){
    pid_t pid = fork();
    if(pid<0){
        fprintf(stderr, "fork error:%s\n", strerror(errno));
        exit(1);
    }else if(pid > 0)//parent process
    {
        wait(0);
        while(1){
            sleep(1);
        }
        printf("parent pid:%d, ppid:%d,  child pid:%d\n",getpid(),getppid(),pid);
    }else{
       printf("child pid:%d, ppid:%d\n",getpid(),getppid());
       exit(1);
    }
    //另开终端 ps -ef|grep a.out查看 <defunct>即为僵死进程
    //没有defunct进程了
    return 0;
}
