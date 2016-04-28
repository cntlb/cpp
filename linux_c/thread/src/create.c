#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//编译时不要忘了添加 pthread 库
void* run(void* args){
	int i = 0;
	while(1){
		printf("thread:%ld, ---> %d\n", pthread_self(), i++);
		sleep(1);
	}
	return (void*)1;
}

int main(){
	
	pthread_t th;
	if(pthread_create(&th, NULL, run, (void*)0) != 0){
		printf("thread create error!\n");
		exit(1);
	}
	
	int i = 0;
    while(1){
        printf("thread:%ld, ---> %d\n", pthread_self(), i++);
        sleep(1);
    }

	return 0;
}
