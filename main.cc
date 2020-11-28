 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-23 15:20:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;
int main(){
	int *p=new int(10);
	
	p->(~int());
	return 0;
}
