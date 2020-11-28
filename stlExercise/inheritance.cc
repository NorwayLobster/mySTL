 ///
 /// @file    inheritance.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-26 00:23:46
 ///
 
#include <iostream>
using std::cout;
using std::endl;
namespace wc{
	class A{
		public:
			void show(){cout<<"a:"<<_a<<endl;}
		private:
			int _a;
	};
	class B
	:virtual public A
//	:public A
	{
		public:
			void print(){cout<<"b:"<<_b<<endl;}
		private:
			int _b;
	};
	class C
	:virtual public A
//	:public A
	{
		public:
			void print(){cout<<"c:"<<_c<<endl;}
		private:
			int _c;
	};
	class D
	:public B
	,public C
	{
		public:
//			void print(){cout<<"d:"<<_d<<endl;}
		private:
			int _d;

	};
}
int main(){
	wc::D d;
	cout<<"sizeof(A):"<<sizeof(wc::A)<<endl;
	cout<<"sizeof(B):"<<sizeof(wc::B)<<endl;
	cout<<"sizeof(C):"<<sizeof(wc::C)<<endl;
	cout<<"sizeof(D):"<<sizeof(wc::D)<<endl;
	//1. 多重继承的二义性: 成员名冲突--solution:作用域限定符
//	d.print();
	d.wc::B::print();
	d.wc::C::print();
	//2.  菱形继承, 多重继承的二义性:存储空间的二义性--solution:Virtual继承
	d.show();
	return 0;
}
