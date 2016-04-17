#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

//http://www.jikexueyuan.com/course/1624_1.html?ss=1 例子
int main(void)
{
    pid_t pid;
    pid = fork();
    if(pid < 0)
    {
        fprintf(stderr,"fork error %s\n",strerror(errno));
        exit(1);
    }else if(pid > 0)
    {
        sleep(3);
        printf("parent pid: %d,ppid: %d\n",getpid(),getppid());
        exit(1);
    }
    else
    {
        printf("child pid: %d,ppid: %d\n",getpid(),getppid());
    }
    sleep(5);
    printf("child pid: %d,ppid: %d\n",getpid(),getppid());
    return 0;
}
