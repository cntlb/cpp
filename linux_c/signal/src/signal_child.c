#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

void signal_handle(int signo){
	printf("signal no:%d------------\n", signo);
}

void out(const char* str){
    int i = 0;
    while(1){
        printf("%s process is running, pid:%d, n = %d\n", str, getpid(), i++);
        sleep(1);
    }
}

int main(void){
    //当一个进程调用fork时，子进程继承父进程的信号处理方式
    //SIGTSTP: 前台进程挂起(Ctrl+z)
    //Ctrl+c 父进程和子进程同时结束
	if(signal(SIGTSTP, signal_handle) == SIG_ERR){
		fprintf(stderr, "signal error:%s\n", strerror(errno));
		exit(1);
	}
	
	pid_t pid = fork();
	if(pid < 0){
	    fprintf(stderr, "fork error:%s\n", strerror(errno));
	    exit(1); 
	}else if(pid > 0){
	    out("parent");
	}else{
	    out("chlid");
	}
	return 0;
}
