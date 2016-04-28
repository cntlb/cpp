#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <malloc.h>

typedef struct data{
	int from;
	int to;
} Data;

void* run(void* args){
	Data* dt = (Data*)args;
	int* sum = (int*)malloc(sizeof(int));
	*sum = dt->from;
	int i;
	for(*sum=0, i=dt->from; i<=dt->to; i++){
		*sum += i;
	}
	return (void*)sum;
}

int main(int argc, char* args[]){
	
	if(argc<3){
		fprintf(stderr, "Usage: %s from to\n", args[0]);
		fprintf(stderr, "\twhere both from and to are numbers!\n");
		exit(1);
	}	
	Data dt = {atoi(args[1]), atoi(args[2])};

	pthread_t th;

	if(pthread_create(&th, NULL, run, (void*)&dt) != 0){
		printf("thread create error!\n");
		exit(1);
	}
	
	void* result = NULL;
	if(pthread_join(th, &result) != 0){
		fprintf(stderr, "thread join error:%s\n", strerror(errno));
		exit(1);
	};
	
	printf("result:%d\n",*((int*)result));
	free(result);
	return 0;
}
