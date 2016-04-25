#include <string>
#include "student.h"
using namespace std;

student::student():age(0),name(""),addr(""){
}

student::student(int age,string name,address addr){
	this->age = age;
	this->name = name;
	this->addr = addr;
}
void student::setAddr(address addr){
	this->addr = addr;
}
address student::getAddr(){
	return addr;
}

