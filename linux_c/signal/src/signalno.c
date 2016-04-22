#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

void signal_handle(int signo){
	printf("signal no:%d------------\n", signo);
}

int main(void){
    /*
    信号宏定义在 /usr/include/x86_64-linux_gnu/bits/signum.h
    
    signal系统调用  void (*signal(int  sig , void (*func)(int)))(int);
    参数：sig： 信号编号
        void (* func )(int)：信号处理函数
    返回值：类型是一个信号处理函数的函数指针
        SIG_ERR  	错误返回结果 		(void(*)(int))(-1)
        SIG_IGN  	忽略某个信号 		(void(*)(int))(0)
        SIG_DFL 	默认处理某个信号 	(void(*)(int))(1)
    */
    //SIGINT:前台进程中断(Ctrl+c)
	if(signal(SIGINT, signal_handle) == SIG_ERR){
		fprintf(stderr, "signal error:%s\n", strerror(errno));
		exit(1);
	}
	
	int i = 0;
	while(1){
		printf("%d \n", i++);
		sleep(1);
	}
	return 0;
}
