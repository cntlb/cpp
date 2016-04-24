#include <stdio.h>
#include <time.h>

int main(){
	time_t now;
	time(&now);	
	printf("now time in second is:%ld\n",now);
	return 0;
}
