///
/// @file    string.h
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-02-23 14:05:41
///
#ifndef __STRING__H__
#define __STRING__H__
#include <iostream>
using std::cout;
using std::endl;
namespace wc{
class String
{
	public:
		String();
		//const reference can not tell the difference of lvalue and rvalue
		String(const char *pstr);
		String(const String & rhs);

		//so, introduce rvalue reference in c++11
		String(String && rhs);//when it is rvalue, call this by priority
		String & operator=(String && rhs);

		String & operator=(const String & rhs);
		String & operator=(const char *p);

		String & operator+=(const String & rhs);
		String & operator+=(const char *p);

		char & operator[](std::size_t);
		const char & operator[](std::size_t)const;

		
		friend bool operator!=(const String&,const String&);
		friend bool operator==(const String&,const String&);

		friend bool operator<=(const String&,const String&);
		friend bool operator<(const String&,const String&);

		friend bool operator>=(const String&,const String&);
		friend bool operator>(const String&,const String&);

//		friend std::ostream &operator<<(std::ostream&,const String &);
//		friend std::ostream &operator>>(std::istream&, String &);
//
		~String();

		std::size_t size()const;
		const char * c_str()const;
		const char * data()const;
		void print();

	private:
		char * _pstr;
};

String operator+(const String &lhs,const char *p);
String operator+(const String &lhs,const String &rhs);
String operator+(const char*p,const String &rhs);
}
#endif
