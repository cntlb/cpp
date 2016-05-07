#include <string>
#include "student.h"

//测试的方便,设置了非默认的初值
student::student():age(30),name("origin name"),addr("China"){}

student::student(int age,string name,string addr){
	this->age = age;
	this->name = name;
	this->addr = addr;
}

int student::getAge(){ return age;}

void student::setAddr(string addr){
	this->addr = addr;
}
string student::getAddr(){
	return addr;
}

//static function1: no parameter
int student::getNum(){
	return 100;	
}

//static function2
int student::add(int a, int b){
	return a+b;
}

student* student::getInstance(){
	return new student(50, "getInstance", "Earth");
}



