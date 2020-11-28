///
/// @file    referenceDeadLoop.cc
/// @author  ChengWANG(cheng.wang.801@gmail.com)
/// @date    2020-04-25 19:53:47
///

#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;
#if 1
namespace wc{
	class Child;
	class Parent{
		public:
			Parent(){cout<<"Parent()"<<endl;}
			~Parent(){cout<<"~Parent()"<<endl;}
			weak_ptr<Child> _childPtr;
			//shared_ptr<Child> _childPtr;
		private:
	};
	class Child{
		public:
			Child(){cout<<"Child()"<<endl;}
			~Child(){cout<<"~Child()"<<endl;}
			shared_ptr<Parent> _parentPtr;
//			shared_ptr<Child> _parentPtr;
		private:
	};
}
int main(){
	shared_ptr<wc::Parent> parentPtr(new wc::Parent);
	shared_ptr<wc::Child> childPtr(new wc::Child);
	cout<<"childPtr.use_count():"<<childPtr.use_count()<<endl;
	cout<<"parentPtr.use_count():"<<parentPtr.use_count()<<endl;

	parentPtr->_childPtr=childPtr;
	childPtr->_parentPtr=parentPtr;
	cout<<"childPtr.use_count():"<<childPtr.use_count()<<endl;
	cout<<"parentPtr.use_count():"<<parentPtr.use_count()<<endl;

	return 0;
}
#endif
