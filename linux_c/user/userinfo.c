#include <stdio.h>
#include <unistd.h>

int main(){
	
	printf("uid:%d\n", getuid());
	printf("gid:%d\n", getgid());
	printf("username:%s\n", getlogin());

	return 0;
}
