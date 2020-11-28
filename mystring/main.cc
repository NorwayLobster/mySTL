///
/// @file    testString.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-23 14:09:40
///

#include <iostream>
#include "string.hpp"
using std::cout;
using std::endl;

int main(void)
{
	wc::String str1;
//	str1.print();
	cout<<endl;
	wc::String str1_2 = wc::String("Hello,world");//临时对象 生成
	str1_2.print();
	str1_2 = wc::String("Hello, Universe");//临时对象 生成
	str1_2.print();
	cout<<"--itself-----"<<endl;
//	str1_2=std::move(str1_2);
	cout<<"--------"<<endl;

	wc::String str2 = "Hello,world";//临时对象 生成
	str2.print();

	cout<<"--------"<<endl;

	cout<<endl;

	wc::String str3("wangdao");
	str3.print();


	cout<<endl;
	wc::String str4 = str3;
	str4.print();

	cout<<endl;
	str4 = str2;
	str4.print();
	cout<<endl;

	str4 = str4;
	cout<<endl;
	
	cout<<"--------"<<endl;
	str4+="hello";
	str4.print();

	str4 += str3;
	str4.print();
	
	cout<<str4[10]<<endl;
	str4[10]='Z';
	cout<<str4[10]<<endl;
	str4.print();
	
	cout<<"-----------------------"<<endl;
	(str4+"hell").print();
	("hell"+str4).print();
	(str3+str4).print();

	cout<<"--------"<<endl;
	str3.print();
	str4.print();
//	if(str3!=str4)
//	if(str3==str4)
//	if(str3>=str4)
//	if(str3>str4)
//	if(str3<str4)
	if(str3<=str4)
		cout<<"true"<<endl;
	else 
		cout<<"false"<<endl;
#if 0
#endif
	return 0;
}
