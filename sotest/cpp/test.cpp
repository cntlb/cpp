#include <dlfcn.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

class student{
public:
	int age;
	string name;
	string addr;
	void display(){
		cout <<"age:"<<age<<endl
	 		 <<"name:"<<name<<endl
			 <<"address:"<<addr<<endl;
	}
};

//test libstu.so
int main(void)
{
	void* handle = dlopen("./libstu.so", RTLD_LAZY);
	if(handle == NULL){
		cout << "open libstu.so error!" << endl;	
		exit(1);
	}
 	
	cout<<"**********************test static function*********************"<<endl;
	// get static symbol
	// just 1 parameter, both int (*)() and int (*)(void*) are ok
	int (*student_static_getNumEv)();
	student_static_getNumEv = (int (*)())dlsym(handle, "_ZN7student6getNumEv");
	cout<< student_static_getNumEv() << endl;


	int (*student_static_addEii)(int,int);
	student_static_addEii = (int (*)(int,int))dlsym(handle, "_ZN7student3addEii");
	//if use type int (*)(void*,int,int) and then pass a NULL pointer, will return 10.
	//So,the right type without class pionter  
	cout<< student_static_addEii(10, 20) << endl;

	typedef student* (*GetInstance)();
	GetInstance getInstance;
	getInstance = (GetInstance)dlsym(handle, "_ZN7student11getInstanceEv");
	student* s = getInstance();
	s->display();//ok

	/*
	typedef student* (*GetInstanceE)(void*);
	GetInstanceE getInstanceE = (GetInstanceE)getInstance;
	student *s1;
	getInstanceE(s1);
	s1->display();//不是预期的对象
	*/

	cout<<"*************************test constructor*******************************"<<endl;

	typedef student* (*Constructor)(student*);
	Constructor c;
	c = (Constructor)dlsym(handle, "_ZN7studentC2Ev");
	student* stu = new student;
	c(stu);
	stu->display();//ok
					/*
					age:30
					name:origin name
					address:china
					*/
	/*
	student* stu1 = new student;
	stu1 = c(stu1);
	stu1->display();//Segmentation fault
	*/

	typedef void (*Constructor2)(student*);
	Constructor2 c2 = (Constructor2)c;
	student* stu2= new student;
	c2(stu2);
	stu2->display();// also ok!

	delete stu;
	delete stu2;
	/*
	总结(结合面向对象编程的基本思想):
		这里对才c++中的静态函数和改造函数进行了符号解析(解析自so共享库, 而不是编译时链接),可以发现:
		1. 静态函数即使变成了汇编代码, 虽然so符号中还是有一个"E"(_ZN7student3addEii),仍然与对象无关, 因此无需传入对象指针. 普通函数第一个没人的就是指向当前对象的指针(student *__hidden this)
		2. 构造函数既有返回值也无返回值, 因此返回void*和void都允许(否则没办法定义函数指针)
	*/
	return 0;
}
