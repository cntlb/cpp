#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	time_t now;
	time(&now);	
	struct tm *t;
	t = localtime(&now);
	if(t == NULL){
		printf("error get time!\n");
		exit(1);
	}
	printf("year :%4d\n", t->tm_year+1900);//相对于1900年1月1日
	printf("month:%4d\n", t->tm_mon);//月份0-11
	printf("day  :%4d\n", t->tm_mday);//
	printf("hour :%4d\n", t->tm_hour);//已经是本地时间了
	printf("min  :%4d\n", t->tm_min);
	printf("sec  :%4d\n", t->tm_sec);
	printf("今年的第%4d天\n", t->tm_yday);
	
	return 0;
}
