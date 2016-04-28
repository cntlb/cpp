#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int total = 150;

typedef struct data{
	char name[20];
	int amount;
}data;

void* run(void* args){
	data* d = (data*)args;
	printf("-------------\n");
	if(total >= d->amount){
		printf("%s get money %d\n", d->name, d->amount);
		sleep(2);
		total -= d->amount;
	}
	return (void*)1;
}

int main(){
	pthread_t th1;
	pthread_t th2;
	
	data d1 = {"user1", 100};
	if(pthread_create(&th1, NULL, run, (void*)&d1)!=0){
		fprintf(stderr, "pthread_create error:%s\n", strerror(errno));
		exit(1);
	}
	
/*
	data d2 = {"user2", 100};
	if(pthread_create(&th2, NULL, run, (void*)&d2)!=0){
		fprintf(stderr, "pthread_create error:%s\n", strerror(errno));
		exit(1);
	}
	
*/
	return 0;
}
