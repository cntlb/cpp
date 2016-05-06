#include <stdio.h>
typedef unsigned char bool;
typedef struct {
    bool invulnerable;	// 0
    bool flying;		// 1
    bool mayfly;		// 2
    bool instabuild;	// 3
    //bool wtf;			// 4
    char fill[3];       //5
    float walkingSpeed; //8
    float flyingSpeed;  //12
} Abilities;

int main(){
	Abilities a1;
	printf("flying at:%p\n", &a1.flying);
	printf("fill   at:%p\n", a1.fill);
	return 0;
}
/*
未注释掉第8行编译运行输出:
flying at:0x7fffa98a6b21
fill   at:0x7fffa98a6b25

注释掉第8行编译运行输出:
flying at:0x7fff08e24a01
fill   at:0x7fff08e24a04

说明数组是按照元素进行对齐而不是整个数组, 毕竟读取的时候是按照每个元素读的
*/
