#include <iostream>
using namespace std;

const int maxsize=6;
class stack{
  private:
    float data[maxsize];
    int top;
  public:
    stack(void);
    ~stack(void);
    bool empty(void);
    void push(float a);
    float pop(void);
};

int main(){
  stack s1,s2;
  int i;
  for(i=1;i<=maxsize;i++)
    s1.push(2*i);
  for(i=1;i<=maxsize;i++)
    cout<<s1.pop( )<<" ";
  for(i=1;i<=maxsize;i++)
    s1.push(2.5*i);
  for(i=1;i<=maxsize;i++)
    s2.push(s1.pop( ));
  cout<<endl;
  do
    cout<<s2.pop( )<<" ";
  while(!(s2.empty( )));

	return 0;
}


stack::stack(void){
  top=0;
  cout<<"stack initialized."<<endl;
}

stack:: ~stack(void){
  cout<<"stack destroyed"<<endl;
}

bool stack::empty(void){
  return top == 0;
}

void stack::push(float a){
  *(data+top) = a;
  top++;
}

float stack::pop(void){
  return *(data+(top--));
}

