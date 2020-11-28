 ///
 /// @file    std_sharedPtr.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-25 18:22:27
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
namespace wc{
	class Point{
		public:
			Point(int x, int y)
			:_x(x)
			,_y(y)
			{cout<<"Point()"<<endl;}
			~Point(){cout<<"~Point()"<<endl;}
			void print() const{cout<<"_x:"<<_x<<",_y"<<_y<<endl;}
		private:
			int _x;
			int _y;
	};
	class Deleter{
		public:
		void operator()(Point* p){
			cout<<"deleter"<<endl;
			delete p;
		}
	};
}
int main(){
	shared_ptr<wc::Point> sp1(new wc::Point(10,21));
//1. ctor is limted, to see cppreference// weak_ptr不能单独存在
	weak_ptr<wc::Point> wp1(sp1);
//	unique_ptr<wc::Point,wc::Deleter> sp2=sp1;

//2. access is limited,  
//	wp1->print();//不能访问资源
	sp1->print();

	//权限提升
	shared_ptr<wc::Point> sp_wp=wp1.lock();//
	if(sp_wp){//
		sp_wp->print();
	}else{//已经不存活了,过期了
		cout<<"fail to create a new shared_ptr"<<endl;
	}
//1.ctor
	cout<<sp1.get()<<endl;
	cout<<endl;

//2. get()
	cout<<sp1.get()<<endl;
//	cout<<sp1.use_count()<<endl;

	cout<<endl;

//3. reset()
	sp1.reset(new wc::Point(1,200));
//4. copy ctor=delete;	
//	 operator=delete;
//	unique_ptr<wc::Point,wc::Deleter> sp2=sp1;
//	unique_ptr<wc::Point,wc::Deleter> sp3(sp1);
	
	return 0;
}
