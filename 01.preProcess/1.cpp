#include <iostream>
#include <string>
using namespace std;

//# 和 ## 操作符是和#define宏使用的. 
//使用# 使在#后的首个参数返回为一个带引号的字符串
#define toString(s) #s

//使用##连结##前后的内容
#define cat(s1,s2) s1##s2
int main(){
	
    cout << toString(Hello #!) << endl;
    
    string str("hello, world!");
    //连接 s和tr
    cout << cat(s, tr) << endl;

	return 0;
}
