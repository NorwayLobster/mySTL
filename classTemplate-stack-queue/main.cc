 ///
 /// @file    main.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 15:19:38
 ///
 
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;
int main(){
	wc::Queue<int,5> q;
	q.push(10);
	cout<<"q.size():"<<q.size()<<endl;
	cout<<"q.front():"<<q.front()<<endl;
	cout<<"q.back():"<<q.back()<<endl;
	q.pop();
	cout<<"-----pop()"<<endl;
	cout<<"q.size():"<<q.size()<<endl;
	cout<<"q.front():"<<q.front()<<endl;
	cout<<"q.back():"<<q.back()<<endl;
	cout<<"-----"<<endl;
	q.push(9);
	cout<<"q.size():"<<q.size()<<endl;
	q.push(11);
	cout<<"q.size():"<<q.size()<<endl;
	q.push(12);
	cout<<"q.size():"<<q.size()<<endl;
	q.push(14);
	cout<<"-----"<<endl;
	cout<<"q.size():"<<q.size()<<endl;
	cout<<"q.front():"<<q.front()<<endl;
	cout<<"q.back():"<<q.back()<<endl;
	return 0;
}
