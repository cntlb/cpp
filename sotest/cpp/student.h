#include <string>
using namespace std;
class student{
public:
	int age;
	string name;
	string addr;
	
public:
	student();
	student(int age,string name,string addr);
	int getAge();
	void setAddr(string addr);
	string getAddr();
	static int getNum();
	static int add(int a, int b);
	static student* getInstance();
};
