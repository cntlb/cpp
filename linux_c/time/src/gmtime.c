#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	time_t now;
	time(&now);	
	struct tm *t;
	t = gmtime(&now);
	if(t == NULL){
		printf("error get time!\n");
		exit(1);
	}
	printf("year :%4d\n", t->tm_year+1900);//相对于1900年1月1日
	printf("month:%4d\n", t->tm_mon+1);//月份0-11
	printf("day  :%4d\n", t->tm_mday);//
	printf("hour :%4d\n", t->tm_hour+8);//将格林尼治时间转化为北京时间
	printf("min  :%4d\n", t->tm_min);
	printf("sec  :%4d\n", t->tm_sec);
	printf("今年的第%4d天\n", t->tm_yday);
	
	return 0;
}
