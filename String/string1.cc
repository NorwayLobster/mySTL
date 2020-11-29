 ///
 /// @file    string1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-28 23:27:33
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A{
public:
	~A(){
	cout<<"~A"<<endl;
	}
};
int main(void)
{
	A a;
	return 0;
}
