///
/// @file    std_allocator.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-04-23 13:07:49
///

#if 1
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
namespace wc{
	class Point{
		public:
			Point(int x=0,int y=0);
			~Point();
			void print();
		private:
			int _x;
			int _y;
	};
	Point::Point(int x,int y)
		:_x(x)
		 ,_y(y)
	{
		cout<<"Point(int x,int y)"<<endl;
	}
	Point::~Point()
	{
		cout<<"~Point()"<<endl;
	}
	void Point::print(){
		cout<<"x:"<<_x<<",y:"<<_y<<endl;
	}

}
int main(){
	using Pointer=wc::Point*;
	std::allocator<wc::Point> alloc;

	Pointer pnew=alloc.allocate(3);
//	alloc.construct(pnew,wc::Point(1,2));//construct():对placement-new的封装
	pnew=new(pnew) wc::Point(1,2);
//	alloc.construct(pnew,wc::Point(1,2));
//	alloc.construct(pnew+1,wc::Point(11,21));
//	alloc.construct(pnew+2,wc::Point(21,22));

	pnew->print();
	(pnew+1)->print();//没构造对象怎么调用的函数？ 答 编译器并不知道有没有对象构造，把只是无脑的把相应的位置按照对象镜像解析; 成员函数存储在代码段,
	(pnew+2)->print();

	pnew->~Point();
//	alloc.destroy(pnew);

	alloc.destroy(pnew+1);
	alloc.destroy(pnew+2);
	alloc.deallocate(pnew,3);
	return 0;
}

#endif




#if 0
#include <memory>
#include <iostream>
#include <string>

int main()
{
	std::allocator<int> a1;   // default allocator for ints
	int* a = a1.allocate(1);  // space for one int
	a1.construct(a, 7);       // construct the int
	std::cout << a[0] << '\n';
	a1.deallocate(a, 1);      // deallocate space for one int

//	default allocator for strings
	std::allocator<std::string> a2;

	// same, but obtained by rebinding from the type of a1
	decltype(a1)::rebind<std::string>::other a2_1;

	// same, but obtained by rebinding from the type of a1 via allocator_traits
	std::allocator_traits<decltype(a1)>::rebind_alloc<std::string> a2_2;

	std::string* s = a2.allocate(2); // space for 2 strings

	a2.construct(s, "foo");
	a2.construct(s + 1, "bar");

	std::cout << s[0] << ' ' << s[1] << '\n';

	a2.destroy(s);
	a2.destroy(s + 1);
	a2.deallocate(s, 2);
}
#endif
