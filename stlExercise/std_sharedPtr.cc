 ///
 /// @file    std_sharedPtr.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-25 18:22:27
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
namespace wc{
	class Point{
		public:
			Point(int x, int y)
			:_x(x)
			,_y(y)
			{cout<<"Point()"<<endl;}
			~Point(){cout<<"~Point()"<<endl;}
		private:
			int _x;
			int _y;
	};
}
int main(){
	shared_ptr<int> sp;	

//1.ctor
	shared_ptr<wc::Point> sp1(new wc::Point(10,21),[](auto p){cout<<"deleter"<<endl;delete p;});//c++17
	cout<<sp1.get()<<endl;
	{
//4. copy cotor 
//	 operator=()
		shared_ptr<wc::Point> sp2=sp1;
		cout<<sp2.get()<<endl;
		cout<<sp2.use_count()<<endl;
	}
	cout<<endl;

//2.  get()
	cout<<sp1.get()<<endl;
	cout<<sp1.use_count()<<endl;

	cout<<endl;

//3.  reset()
	sp1.reset(new wc::Point(1,200));

	return 0;
}
