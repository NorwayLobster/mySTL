#include <cstring>
//#include <string.h>

#include "String.hpp"

namespace wc{

String::String():
_pstr(NULL)//very vital
{
	cout<<"String()"<<endl;
}

String::String(const char *p):
_pstr(new char[strlen(p)+1]())
{
	::strcpy(_pstr,p);
	cout<<"String(const char *p)"<<endl;
}

String::String(const String &s):
_pstr(new char[strlen(s._pstr)+1]())
{
	strcpy(_pstr,s._pstr);
	cout<<"String(const String &s)"<<endl;
}

String::String(String &&rhs)
:_pstr(rhs._pstr)
{
	cout<<"String(String &&)"<<endl;
	rhs._pstr=NULL;
}

String & String::operator=(String && rhs){
	cout<<"String &operator=(String &&s)"<<endl;
	if(this!=&rhs){//assign itself
		cout<<"flag"<<endl;
		delete [] _pstr;
		_pstr=rhs._pstr;
		rhs._pstr=NULL;
	}
	return *this;
}

String & String::operator=(const String & rhs)// 三部曲： 1， 自复制，2.深拷贝，3回收原空间
{
	cout<<"String &operator=(const String &s)"<<endl;
//error	~String();
	if(this!=&rhs){//防止自复制
		this->~String();
		_pstr=new char[strlen(rhs._pstr)+1]();
		strcpy(_pstr,rhs._pstr);
	}
	return *this;
}

char &String::operator[](std::size_t index){
	return *(_pstr+index);
}

const char &String::operator[](std::size_t index)const{
	return *(_pstr+index);
}

String &String::operator=(const char*p)
{
	if((void*)p!=(void*)_pstr){
//	if((void*)p!=(void*)this){
		delete [] _pstr;	
		_pstr=new char[strlen(p)+1]();
		strcpy(_pstr,p);
		cout<<"String &operator=(const char *p)"<<endl;
	}
	return *this; 
}

String &String::operator+=(const String &rhs){
	int len=strlen(_pstr)+rhs.size();
	char * tmp;
	tmp=new char[len+1]();
	memcpy(tmp,_pstr,this->size());
//	memcpy(tmp,_pstr,strlen(_pstr));
	delete [] _pstr;	
	memcpy(tmp+strlen(tmp),rhs.c_str(),rhs.size());
	_pstr=tmp;
	return *this;
}

String& String::operator+=(const char*p){
	int len=this->size()+strlen(p);
	char * tmp=new char[len+1];
	memcpy(tmp,_pstr,this->size());
	delete [] _pstr;
	_pstr=tmp;
	memcpy(_pstr+strlen(_pstr),p,strlen(p));
	return *this;
}

bool operator==(const String &lhs, const String &rhs){
	return strcmp(lhs.c_str(),rhs.c_str())==0?1:0;
}
bool operator!=(const String &lhs, const String &rhs){
	return strcmp(lhs.c_str(),rhs.c_str())!=0?1:0;
}
bool operator<=(const String &lhs, const String &rhs){
	return strcmp(lhs.c_str(),rhs.c_str())<=0?1:0;
}
bool operator<(const String &lhs, const String &rhs){
	return strcmp(lhs.c_str(),rhs.c_str())<0?1:0;
}
bool operator>=(const String &lhs, const String &rhs){
	return strcmp(lhs.c_str(),rhs.c_str())>=0?1:0;
}
bool operator>(const String &lhs, const String &rhs){
	return strcmp(lhs.c_str(),rhs.c_str())>0?1:0;
}

String operator+(const String &lhs,const char *p){			
	String tmp(lhs);
	tmp+=p;	
	return tmp;
}
String operator+(const String &lhs,const String &rhs){			
	String tmp(lhs);
	tmp+=rhs;
	return tmp;
}
String operator+(const char*p,const String &rhs){
	String tmp(p);
	tmp+=rhs;
	return tmp;
}
String::~String(){
	if(NULL!=_pstr){
		delete [] _pstr;
		_pstr=NULL;
	}
	cout<<"~String()"<<endl;
}

std::size_t String::size()const{
	return strlen(_pstr);
}
const char *String::c_str()const{
	return _pstr;
}
const char *String::data()const{
	return _pstr;
}
void String::print(){
	cout<<"String:"<<_pstr<<endl;
}
}
