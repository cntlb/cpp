#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	time_t t;
	time(&t);
	printf("ctime: %s\n", ctime(&t));
	struct tm *_tm;
	_tm = gmtime(&t);
	printf("asctime: %s\n", asctime(_tm));
	return 0;
}
