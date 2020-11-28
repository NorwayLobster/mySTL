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
	class Deleter{
		public:
		void operator()(Point* p){
			cout<<"deleter"<<endl;
			delete p;
		}
	};
}
int main(){
	shared_ptr<int> sp;	

//	unique_ptr<wc::Point,wc::Deleter> sp2=sp1;

//1.ctor
	unique_ptr<wc::Point,wc::Deleter> sp1(new wc::Point(10,21),wc::Deleter());
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
	
//5. move ctor
//   move operator=()
	unique_ptr<wc::Point,wc::Deleter> sp2=std::move(sp1);
	unique_ptr<wc::Point,wc::Deleter> sp3(std::move(sp1));
	std::vector<unique_ptr<wc::Point,wc::Deleter>> v;

//6.	
	cout<<endl;
	//wrong v.push_back(sp2);
	v.push_back(std::move(sp2));
	return 0;
}
