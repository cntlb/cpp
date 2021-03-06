#include <iostream>
using namespace std;
void hanoi(int, char, char, char);
void move(char, char);

/*
Hanoi 塔问题  
 
Hanoi 塔问题是一个古印度著名的智力测验。该问题是这样的:有三个立柱
A、B、C,A 柱上穿有大小不等的圆盘 64 个,较大的圆盘在下,较小者在上。
要求借助于 B 柱把 A 柱上的 64 个圆盘移到 C 柱,规则是:  
(1) 每次只能把一个柱上最上面的圆盘移至另一个柱的最上层。 
(2) 保持在每个柱上的圆盘较大者在下,较小者在上。


*/    
int main(){
    cout << "Input  the  number  of  disks:";
	int time;    
    cin >> time;
    hanoi(time, 'A', 'B', 'C');
	return 0;
}

void hanoi(int time, char a, char b, char c){
    if(time<=0){
        cout << "error!" << endl;
        return;
    }
    
    if(time == 1){
      move(a, c); 
      return; 
    }
    
    hanoi(time-1, a, c, b);
    move(a, c);
    hanoi(time-1, b, a, c);
}
void move(char from, char to){
    cout << from << "-->" << to << endl;
}


