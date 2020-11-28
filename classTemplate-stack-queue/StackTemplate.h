 ///
 /// @file    statckTemplate.cc
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-02-25 21:09:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template<typename T, int Ksize> class Stack{
public:
	Stack();
	~Stack();
	int	size();
	bool full();
	bool empty();
	T top();
	void push(const T &);
	void pop();
private:
	T * _p;
	int  _size;
};

template<typename T, int Ksize> Stack<T,Ksize>::Stack()
:_p(new T[Ksize]())
,_size(0)
{
	cout<<"Stack()"<<endl;
}
template<typename T, int Ksize> Stack<T,Ksize>::~Stack(){
	cout<<"~Stack()"<<endl;
	delete [] _p;
}

template<typename T, int Ksize> T Stack<T,Ksize>::top(){
	if(0!=_size){
		return _p[_size-1];
	}else{//???
		return -1;
	}
}
template<typename T, int Ksize> int Stack<T,Ksize>::size(){
	return _size;
}
template<typename T, int Ksize> void Stack<T,Ksize>::pop(){
	if(0!=_size)
		--_size;
}

template<typename T, int Ksize> bool Stack<T,Ksize>::empty(){
	return 0==_size;
}

template<typename T, int Ksize> bool Stack<T,Ksize>::full(){
	return Ksize==_size;
}
template<typename T, int Ksize> void Stack<T,Ksize>::push(const T & t){
	if(Ksize>_size){
		_p[_size]=t;//_size=0时，放在下标0
		++_size;
	}
}
	
int main(){
	Stack<int,10> s;
	cout<<s.empty()<<endl;
	cout<<s.top()<<endl;
	cout<<s.size()<<endl;
	cout<<s.full()<<endl;
	cout<<endl;
	s.push(1);
	s.push(2);
	s.push(4);
	cout<<s.top()<<endl;
	cout<<s.size()<<endl;
	cout<<s.full()<<endl;

	return 0;
}
