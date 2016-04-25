#include <string>

class address{
public:
	std::string addr;
	address();
	address(std::string addr);
	operator =(address&);
}
