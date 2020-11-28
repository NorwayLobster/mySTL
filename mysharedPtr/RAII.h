 ///
 /// @file    RAII.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-25 16:38:23
 ///
#ifndef _RAII_H_ 
#define _RAII_H_ 
#include <iostream>
using std::cout;
using std::endl;
namespace wc{
	template<typename T>
	class RAII{
		using ValueType=T;
		using Pointer=T*;
		using Reference=T&;
		using ConstReference=T&;
		public:
			RAII(const Pointer);
			~RAII();
		Reference operator*(){ return *_p; }
		Pointer operator->(){ return _p; }
		private:
			Pointer _p;
	};
	template<typename T>
//	RAII<T>::RAII(const ValueType&p)
	RAII<T>::RAII(const Pointer p)
	:_p(p)
	{
		cout<<"RAII(const Pointer&)"<<endl;
	}
	template<typename T>
	RAII<T>::~RAII(){
		cout<<"~RAII()"<<endl;
		delete _p;
	}

}
#endif

