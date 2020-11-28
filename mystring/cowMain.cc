 ///
 /// @file    cowMain.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-25 01:12:37
 ///
 
#include <iostream>
#include <string>
#include "cowString.hpp"
using std::cout;
using std::endl;
int main(){
	wc::CowBasicString<char> s1;
	wc::CowBasicString<char> s2='A';
	cout<<s1.RefCount()<<endl;
	cout<<s1.size()<<endl;

	cout<<"------"<<endl;
	s2.print();
	cout<<s2.RefCount()<<endl;
	cout<<s2.size()<<endl;

	cout<<"------"<<endl;
	wc::CowBasicString<char> s3("hello");

	s3.print();
	cout<<s3.RefCount()<<endl;
	cout<<s3.size()<<endl;

	cout<<"------"<<endl;
	wc::CowBasicString<char> s4=s3;
	s4.print();
	cout<<s4.RefCount()<<endl;
	cout<<s4.size()<<endl;

	cout<<"------"<<endl;
	s4[2]='Z';
	s4.print();
	cout<<s4.RefCount()<<endl;
	cout<<s4.size()<<endl;

	cout<<"--s3---"<<endl;
	s3.print();
	cout<<s3.RefCount()<<endl;
	cout<<s3.size()<<endl;
	
	cout<<"--s6---"<<endl;
	std::string str("World");
	wc::CowBasicString<char> s6(str);
	s6.print();
	cout<<s6.RefCount()<<endl;
	cout<<s6.size()<<endl;
	s6[2]='Z';
	cout<<"--operator[]---"<<endl;
	s6.print();
	cout<<s6.RefCount()<<endl;
	cout<<s6.size()<<endl;
	

	

//	cout<<s2<<endl;	
	return 0;
}

