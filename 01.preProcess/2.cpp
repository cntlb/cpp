
#ifndef __2_CPP
#define __2_CPP
//#undef xyz

#include <iostream>
using namespace std;

#define a 10
#define debug

int main(){

    #ifdef debug
	    cout << "in debug case!"  << endl;
        #if a<0
            cout << "a<0" << endl;
        #elif a<10
            cout << "0<=a<10" << endl;
        #else
            cout << "a>=10" << endl;
        #endif    
    #else
        cout << "in release case!" << endl;
    #endif
	return 0;
}
#endif //__2_CPP

