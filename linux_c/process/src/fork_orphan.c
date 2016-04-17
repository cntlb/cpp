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
        //父进程退出
        printf("parent pid:%d, ppid:%d,  child pid:%d\n",getpid(),getppid(),pid);
        exit(1);
    }else{
       printf("child pid:%d, ppid:%d\n",getpid(),getppid());
       
    }
    sleep(5);//父进程先结束， 则子进程成为孤儿进程，自动被init（1号进程）领养
             //测试的结果被pid为7174的进程领养？
             //ps -ef | grep 7174 该进程是 /sbin/upstart， 并不是init
             //麻痹， 网上哪个脑残说杀死upstart进程会被init领养，他妈的重启了！
             //搜索之：http://www.ibm.com/developerworks/cn/linux/1407_liuming_init2/
             //上面说： Ubuntu 使用了一种被称为 upstart 的新型 init 系统。
    printf("child pid:%d, ppid:%d\n",getpid(),getppid());
    return 0;
}
