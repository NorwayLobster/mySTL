 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-03-27 21:40:12
 ///

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

//error: using std::bool;
int main(void)
{
	char a[]="hello";
	char b[]=", world";
	//1,strcat()
	int length =::strlen(a)+::strlen(b);
	char *p= static_cast<char*>(::calloc(0,length+1));
	char *p1= static_cast<char*>(::calloc(0,length+1));
	::strcpy(p,a);
	::strcat(p,b);
	::printf("%s\n",p);
	char * p11 =::strstr(p,a);
	strncpy(p1,p11,sizeof(a));//定量拷贝
	printf("%s\n",p11);
	printf("p1=%s\n",p1);
	for(int idx=0;idx<length;++idx)
	{
		if(idx<length-1)
			printf("%c ",p[idx]);
		else 
			printf("%c\n",p[idx]);

	}
		
	//c++
	string a1 ="hello";
	string b1 =", world";
	string c1 = a1+b1;
	size_t pos=0;
	//find a subsring in one string 
	pos = c1.find("wor");
	//截取字符串
	string s4 =	c1.substr(pos,strlen("wor"));
	
	cout<<"s4="<<s4<<endl;
	string c2("cheng");
	cout<<"c="<<c1<<" "<<c2<<endl;
	bool A;
	if( a1==b1)
		A=1;
	else 
		A=0;
	cout<<"A="<<A<<endl;





	return 0;
}
