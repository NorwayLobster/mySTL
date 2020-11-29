 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-02 23:05:51
 ///
 
#include <cstdlib>
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
class String
{
public:
	String();
	String(const char*);
	//String(char*);
	String(const String &);
	String &operator=(const String & s);
	char &operator[](int idx);
//	ostream & String::operator[](ostream & cout, int idx);
//	friend ostream &operator<<(ostream & cout);
//eorr:	friend ostream & operator<<(const String & s, ostream & cout);
	friend ostream & operator<<(ostream & cout, const String & s);
	~String();
	void print();
	void printRef();
	//String * c_str(); 
	char * c_str() const; 
	//char * c_str(); 
	//size_t size();
	size_t size() const;
private:
	char*_ptr;
	//int refCount;
};

String::String()
:_ptr(new char[1+4]() + 4)
{
	*(int*)(_ptr-4)=0;	
	cout<<"default constructor"<<endl;
}

String::String(const char*ptr)
//String::String(char*ptr)
:_ptr(new char[::strlen(ptr)+1+4] + 4)
{
	//++refCount;
	++*(int*)(_ptr-4);	
//error: strcpy(_ptr-4, ptr-4);
	strcpy(_ptr, ptr);
	cout<<"normal constructor"<<endl;
}

String::String(const String & s)
:_ptr(s._ptr)
{
	//++refCount;
	++*(int*)(_ptr-4);	
	cout<<"copy constructor"<<endl;
}
String & String::operator=(const String & s)
{
	if(this != &s)
	//error: if(*this != s)
	{
		cout<<"operator="<<endl;
		--*(int*)(_ptr-4);	
		if(*(int*)(_ptr-4)==0)
		{
			delete [] (_ptr-4);
		}
	//error	_ptr = new char[strlen(s._ptr)+1] +4;
	_ptr=s._ptr;
	//error: strcpy(_ptr,s._ptr);\
	// error: strcpy(_ptr-4, _ptr-4);
#ifdef DEBUG
		cout<<"before strcpy() int operator="<<endl;
		cout<<s._ptr<<endl;
#endif
	//	strcpy(_ptr-4, s._ptr-4);
#ifdef DEBUG
		cout<<"after strcpy() int operator="<<endl;
		cout<<_ptr<<endl;
#endif
		++*(int*)(_ptr-4);	
	}
	return *this; 
}	
//ostream & String::operator[](ostream & cout, int idx)
//String & String::operator[](const String & s)
//{
//	cout<<"this->"<<idx<<":"<<this+idx<<endl;
//	return cout;
//}
char & String::operator[](int idx)
{
	if(*(int*)(_ptr-4)>1)
	{
		--*(int*)(_ptr-4);	
		char *p =new char[strlen(_ptr)+1]()+4;
		//assign 0:  char *p =new char[strlen(_ptr)+1]+4;
		strcpy(p,_ptr);
		++*(int*)(p-4);	
		_ptr=p;
	}	
	return *(_ptr+idx);

}
//ostream & operator<<(const String & s, ostream & cout)
ostream & operator<<(ostream & cout, const String & s)
{
	cout<<"*_ptr="<<s._ptr;
	return cout;
}
	
String::~String()
{
//	--refCount;
	--*(int*)(_ptr-4);	
	if(*(int*)(_ptr-4)==0)
	{
		delete [] (_ptr-4);
	}
	cout<<"deconstructor"<<endl;
}

void String::print()
{
	cout<<"*_ptr="<<_ptr<<endl;
}

void String::printRef()
{
	cout<<"refcount="<<*(int*)(_ptr-4)<<endl;

}
//String * String::c_str()
char* String::c_str() const
//char* String::c_str()
{
	//return this;
	return _ptr;
}

size_t String::size() const
//size_t String::size()
{
	return strlen(_ptr);
}
int main(void)
{
	String s;
	s.print();
	s.printRef();
	cout<<"-----------------"<<endl;
	String s1("hello world");
	s1.print();
	cout<<s1<<endl;
	s1.printRef();
	cout<<"-----------------"<<endl;
	String s2= "hello";
	s2.print();
	s2.printRef();
	cout<<"-----------------"<<endl;
	String s3 = s2;
	s3.print();
	s3.printRef();
	cout<<"-----------------"<<endl;
	cout<<"-----------------"<<endl;
	s3 = s1;
	s3.print();
	s3.printRef();
	cout<<"-----------------"<<endl;
	s3[0] = 'H';
	//error: s[0] = "H";
//	s3.print();
	cout<<s3<<endl;
	s3.printRef();
	s1.printRef();
	cout<<"-----------------"<<endl;
	cout<<s2.size()<<endl;
	cout<<s2.c_str()<<endl;
	cout<<"-----------------"<<endl;
	cout<<s3.size()<<endl;
	cout<<s3.c_str()<<endl;
	return 0;
}
		
