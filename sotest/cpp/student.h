#include <string>
#include "address.h"

class student{
public:
	int age;
	std::string name;
	address addr;
public:
	student();
	student(int age,string name,address addr);
	void setAddr(address addr);
	address getAddr();
}
