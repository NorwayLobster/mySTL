 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-23 13:52:01
 ///
 
#include <iostream>
#include "Vector.h"
using std::cout;
using std::endl;
namespace wc{
	class Point{//POD
		public:
			Point(int x=0,int y=0);
			Point(const Point &);
			Point& operator=(const Point &);
			~Point();
			void print()const{cout<<"x:"<<_x<<",y:"<<_y<<endl;}
		private:
			int _x;
			int _y;
	};

	Point::Point(int x,int y)
		:_x(x)
		,_y(y)
	{cout<<"Point(int,int)"<<endl;}

	Point::Point(const Point&rhs)//POD
	:_x(rhs._x)
	,_y(rhs._y)
	{cout<<"Point(const Point&)"<<endl;}

	Point & Point::operator=(const Point&rhs)//POD
	{
		cout<<"operator=(const Point&)"<<endl;
		_x=rhs._x;
		_y=rhs._y;
		return *this;
	}
	Point::~Point()
	{cout<<"~Point()"<<endl;}
}
int main(){
#if 0
	wc::Vector<int> v;
	v.push_back(10);
	cout<<"v.size():"<<v.size()<<endl;
	cout<<"v.capacity():"<<v.capacity()<<endl;
	cout<<v[0]<<endl;
	
#endif
	wc::Vector<wc::Point> v1;
	v1.push_back(wc::Point(1,2));
	v1.push_back(wc::Point(11,22));
//	v1.push_back(std::move(wc::Point(1,2)));
	cout<<"---------------------"<<endl;
	v1[0].print();
	v1[1].print();

	cout<<"---------------------"<<endl;
	v1[0]=v1[1];
	v1[0].print();
	cout<<"--iter------------------"<<endl;
	v1.begin()->print();
	(*v1.begin()).print();

	v1.rbegin()->print();
//	v1.rend();
//	(*((v1.rend())++)).print();


	cout<<"-back()-front()------------------"<<endl;
	v1.push_back(wc::Point(100,2000));
	v1.back().print();
	v1.front().print();

	cout<<"-heap object------------------"<<endl;
	wc::Vector<wc::Point> *p=new wc::Vector<wc::Point>();
	p->push_back(wc::Point(1,2));


	return 0;
}
