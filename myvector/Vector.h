 ///
 /// @file    Vector.h
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-23 13:45:45
 ///
#ifndef _Vector_H_ 
#define _Vector_H_ 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
namespace wc{
	template<typename T>
	class Vector{
		using Value_type=T;
		using Const_reference=const T&;
		using Reference=T&;

		using Pointer=T*;
		using Const_pointer=const T*;

		using Iterator=T*;
		using Const_iterator=const T*;

		public:
			Vector();
			Vector(const Vector &);
			Vector & operator=(const Vector &);
			~Vector();

			void push_back(const Value_type&);
			void pop_back();
			Value_type& front(){ return *_Element;}
			Value_type& back(){return *(--_Free);}
			Const_reference front()const{ return *_Element;}
			Const_reference back()const{ return *(--_Free);}

			Value_type &/*very vital, not to forget it*/ operator[](size_t index){cout<<"operato[]()"<<endl; return *(_Element+index);}
			const Value_type& operator[](size_t index)const{
				cout<<"operator[]()cosnt"<<endl;
				return *(_Element+index);
			}//when it is called, to decide to call which one

			void reserve();
			void resize();
			void clear();//O(N)//destruct all element
			void erase();//O(N)
			void insert();//O(N)
			void swap();
			void shrink_to_fit();


			Iterator begin(){return _Element;}
			Iterator end(){return _Free;}
			Const_iterator cbegin()const {return _Element;}
			Const_iterator cend()const {return _Free;}

			Iterator rbegin(){return --_Free;}
			Iterator rend(){return --_Element;}
			Const_iterator crbegin()const{return --_Free;}
			Const_iterator crend()const{return --_Element;}

			size_t size()const {return size_t(_Free-_Element);};	
			size_t capacity()const{return _EndOfStorage-_Element;}
			bool empty(){return _Element+1==_Free;}
		private:
			void reallocate();
		private:
			static std::allocator<Value_type> _alloc;//just declare, not defining
			Pointer  _Element;	
			Pointer  _Free;	
			Pointer  _EndOfStorage;	
	};
	template<typename T>
	std::allocator<T> Vector<T>::_alloc;//define really
//error:	Vector<T>::allocator<Value_type> _alloc;
	template<typename T>
		Vector<T>::Vector()
		:_Element(nullptr)
		,_Free(nullptr)
		,_EndOfStorage(nullptr)
	{cout<<"Vector()"<<endl;}

	template<typename T>
		Vector<T>::~Vector()
	{	
		cout<<"~Vector()"<<endl;
		for(int i=0;i<size();++i){
			std::allocator_traits<std::allocator<T>>::destroy(_alloc,_Element+i);
//			delete _Element+i;//定点析构placement delete？//i.e. 只析构未释放内存
		}
		_alloc.deallocate(_Element,capacity());
	}
	template<typename T>
	void Vector<T>::push_back(const Value_type &value){
		if(size()==capacity()){
			reallocate();
		}
//		new(_Free)Value_type(value);//construct object 
		std::allocator_traits<std::allocator<T>>::construct(_alloc,_Free,value);
		cout<<"placement new"<<endl;
		++_Free;
	}

	template<typename T>
	void Vector<T>::pop_back(){
		std::allocator_traits<std::allocator<T>>::destroy(_alloc,_Free--);
	}
	template<typename T>
		void Vector<T>::reallocate(){
			Pointer tmp;
			size_t OldCapacity=capacity();
			size_t	NewCapacity=OldCapacity==0?1:2*OldCapacity;//attention: ==  higher than   ?:   >   =
			tmp=_alloc.allocate(NewCapacity);	
			std::uninitialized_copy(_Element,_EndOfStorage,tmp);
			_alloc.deallocate(_Element,OldCapacity);

			_Element=tmp;

			//possiblly wrong
//			_Free=tmp+size();//虽然内存已经释放，但是指针的相对位置不变
//			_EndOfStorage=tmp+capacity();//虽然内存已经释放，但是指针的相对位置不变

			_Free=tmp+OldCapacity;//虽然内存已经释放，但是指针的相对位置不变
			_EndOfStorage=tmp+NewCapacity;//虽然内存已经释放，但是指针的相对位置不变
		}
}
#endif
