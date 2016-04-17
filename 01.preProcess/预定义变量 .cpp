#include <iostream>
#include <stdio.h>
using namespace std;
#define mes (printf("(%s %s)%s:%d\n", __DATE__, __TIME__, __FILE__, __LINE__))
/*

预定义变量 
语法: 
  __LINE__
  __FILE__
  __DATE__
  __TIME__
  _cplusplus
  __STDC__

 

下列参数在不同的编译器可能会有所不同, 但是一般是可用的: 

__LINE__ 和 __FILE__ 变量表示正在处理的当前行和当前文件. 
__DATE__ 变量表示当前日期,格式为month/day/year(月/日/年). 
__TIME__ 变量描述当前的时间,格式为hour:minute:second(时:分:秒). 
_cplusplus 变量只在编译一个C++程序时定义. 
__STDC__ 变量在编译一个C程序时定义,编译C++时也有可能定义.


*/
int main(){
	
    mes;
    
    //#line命令是用于更改__LINE__ 和 __FILE__变量的值. 文件名是可选的.
    #line 200 "line.txt"
    
    mes;
	return 0;
}
