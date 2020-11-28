 ///
 /// @file    std_move.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-25 14:55:39
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
int main(){

//1. right value
	int a=1;	
	&++a;
//	&std::move(a);
//	&(a--);
//	&(a+1);
//	&10;
	const int &b=100;
//	int &c=100;
//2. rvalue reference
	int &&d=100;
	
	string s="hello";
	string s1="world";
	
//3.  std::move
	string s3=std::move(s);
	cout<<"s:"<<s<<endl;
	cout<<"s1:"<<s1<<endl;
	cout<<"s3:"<<s3<<endl;
//4.  对内置类型作用不大
	int z=std::move(a);
	cout<<"a:"<<a<<endl;
	return 0;
}
