#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <syslog.h>


//守护进程
int main(int argc, char *args[]){
    //1.umask屏蔽读写
    umask(0);
        
    //2.fork进程， 退出父进程
    pid_t pid = fork();
    if(pid < 0){
        fprintf(stderr, "fork error:%s\n", strerror(errno));
        exit(1);
    }else if(pid > 0){
        exit(1);
    }    
    
    //3.设置回话和根目录
    setsid();
    chdir("/");
    
    //4.关闭std fds
    close(0);//in
    close(1);//out
    close(2);//err
    
    /*
    int fd = open("d.txt", O_APPEND | O_CREAT | O_TRUNC);
    if(fd < 0){
        fprintf(stderr, "open error:%s\n", strerror(errno));
        exit(1);
    }
    
    
    char*hello = "hello world"; 
    while(1){
        //write(fd, hello, strlen(hello));
        sleep(3);
    }
    close(fd);
    */
    
    char *str = "hello world"; 
    openlog(args[0], LOG_PID, LOG_SYSLOG);
    while(1){
        syslog(LOG_DEBUG, "%s", str);
        sleep(3);
    }
    closelog();
    //日志文件在 /var/log/syslog
    return 0;
}
