 ///
 /// @file    Queue.h
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-22 14:33:40
 ///
 
#ifndef _Queue_H_
#define _Queue_H_
#include <iostream>
#include <cmath>
#include <cstring>
using std::cout;
using std::endl;
namespace wc{
template<typename T,int KSize> 
class Queue{
public:
	Queue();
	Queue(const Queue&);
	Queue& operator=(const Queue&);
	~Queue();
	bool full();
	bool empty();
	int size();
	T front();
	T back();
	void push(const T&);
	void pop();
private:
	T _base[KSize];	
	int _rear;
	int _front;
};

template<typename T,int KSize>
Queue<T,KSize>::Queue()
:_rear(0)
,_front(0)
{
	memset(_base,0,KSize);
	cout<<"Queue()"<<endl;
}

template<typename T,int KSize>
Queue<T,KSize>::Queue(const Queue&queue)
:_rear(queue._rear)
,_front(queue._front)
{
	memcpy(_base,queue._base,KSize);
	cout<<"Queue(const Queue&queue)"<<endl;
}

template<typename T,int KSize>
Queue<T,KSize>& Queue<T,KSize>::operator=(const Queue&queue)
{
	
	_rear=queue._rear;
	_front=queue._front;
	memcpy(_base,queue._base,KSize);
	return *this;
}

template<typename T,int KSize>
Queue<T,KSize>::~Queue()
{
	cout<<"~Queue()"<<endl;
}



template<typename T,int KSize>
void Queue<T,KSize>::push(const T&element){
	if(!full()){
		_base[_rear]=element;
		_rear=++_rear%KSize;
	}else{
		cout<<"full()"<<endl;
	}
}

template<typename T,int KSize>
void Queue<T,KSize>::pop(){
	if(!empty()){
		_front=(_front+1)%KSize;
	}else{
		cout<<"empty()"<<endl;
	}
}
template<typename T,int KSize>
T Queue<T,KSize>::front(){
	if(!empty()){
		return _base[_front];
	}else{
		cout<<"empty()"<<endl;
		return T();
	}
}

template<typename T,int KSize>
T Queue<T,KSize>::back(){
	if(!empty()){
		return _base[(_rear-1+KSize)%KSize];
	}else{
		cout<<"empty()"<<endl;
		return T();
	}

//	return _base[(_rear+KSize)%KSize];
}

template<typename T,int KSize>
bool Queue<T,KSize>::empty(){
	return _rear==_front;
}

template<typename T,int KSize>
bool Queue<T,KSize>::full(){
	return _front==((_rear+1)%KSize);
}

template<typename T,int KSize>
int Queue<T,KSize>::size(){
	return std::abs(_rear-_front);
}

}//end of namespace wc
#endif

