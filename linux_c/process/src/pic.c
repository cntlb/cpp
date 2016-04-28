#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

//通过popen在进程间创建管道,进行通信 
int main(){
	
	FILE * ls;
	if((ls = popen("ls -l /", "r"))== NULL){
		fprintf(stderr, "popen error%s\n", strerror(errno));
		exit(1);
	}
	char msg[100] = {'\0'};
	while(fgets(msg, sizeof(msg), ls) != 0){
		printf("%s", msg);
	}	

	return 0;
}
