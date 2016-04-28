#include <string>
//#include "address.h"
using namespace std;
class student{
public:
	int age;
	string name;
	string addr;
	
public:
	student();
	student(int age,string name,string addr);
	void setAddr(string addr);
	string getAddr();
	static int getNum();
	static int add(int a, int b);
};
