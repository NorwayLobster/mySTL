 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-01 16:35:38
 ///
 
#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;


int main(void)
{	//ubuntu 14.04 std::string 实现采用的是 COW(写时复制)技术
	string s1 = "hello,world";
	string s2 = "fjlajflsjfljsfjsfjsjf;sjf;sjf;sjfrisjf;dsjfjf;a";
	string s3 = s2;
	string s4 = s3;

	cout << "sizeof(s1) = " << sizeof(string) << endl;
	cout << "sizeof(s2) = " << sizeof(s2) << endl;
	//cout << "&s2 = " << &s2 << endl;//error
	cout << "s2 = " << s2.c_str() << endl;
	printf("&s2 = %p\n", s2.c_str());
	printf("&s3 = %p\n", s3.c_str());
	printf("&s4 = %p\n", s4.c_str());

	s2[0] = 'F';
	cout << "修改完s2之后:" << endl;
	printf("&s2 = %p\n", s2.c_str());
	printf("&s3 = %p\n", s3.c_str());
	printf("&s4 = %p\n", s4.c_str());
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;

	return 0;
}
