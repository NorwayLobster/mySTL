 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-25 16:55:55
 ///
 
#include <iostream>
#include <string>
#include "RAII.h"
using std::cout;
using std::endl;
namespace wc{
	class Point{
		public:
			Point(){cout<<"Point()"<<endl;}
			Point(int x,int y)
			:_x(x)
			,_y(y)
			{cout<<"Point()"<<endl;}
			~Point(){cout<<"~Point()"<<endl;}
			void print()const{
				cout<<"x:"<<_x<<",y:"<<_y<<endl;
			}

			friend std::ostream & operator<<(std::ostream&os,const Point &);
		private:
			int _x;
			int _y;
	};
		std::ostream& operator<<(std::ostream&os,const Point &rhs){
			os<<"x:"<<rhs._x<<",y:"<<rhs._y<<endl;
			return os;
		}
}
int main(){
//	wc::RAII<int> raii(new int(10));
	wc::RAII<wc::Point> raii1(new wc::Point(10,12));
	cout<<*raii1<<endl;
	cout<<endl;
	raii1->print();
	cout<<"-------------------"<<endl;
	wc::RAII<std::string> raii2(new std::string("hello world"));
	cout<<*raii2<<endl;
	cout<<raii2->size()<<endl;
	return 0;
}
