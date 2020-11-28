 ///
 /// @file    CowString.hpp
 /// @author  ChengWANG(cheng.wang.801@gmail.com)
 /// @date    2020-04-25 00:38:17
 ///
 
#ifndef _Cow_String_H_
#define _Cow_String_H_
#include <iostream>
#include <cstring>
#include <string>
using std::cout;
using std::endl;
namespace wc{
	template <typename T>
	class CowBasicString{
		using typeValue=T;
		using Pointer=T*;
		using ConstReference=const T&;
		using Reference=T&;
		public:
			CowBasicString();
			CowBasicString(const std::basic_string<T> &);
//			CowBasicString(const std::string &);
			CowBasicString(const char&);
			CowBasicString(const char*);

			CowBasicString(const CowBasicString&);
			CowBasicString&operator=(const CowBasicString&);
			~CowBasicString();
			void print()const{ cout<<_pstr<<endl;}
			int size()const {return strlen(_pstr);}
			typeValue& operator[](const size_t &index)const;//{return *(_pstr+index);}
			typeValue& operator[](const size_t &index);//{return *(_pstr+index);}
//			int capacity()const {return strlen(_pstr);}
			int RefCount() const{ return *(int*)(_pstr-4); }
			//wrong:friend std::ostream& operator<<(std::ostream&os,const CowBasicString&rhs);
//			friend template<typename T> std::ostream& operator<<(std::ostream&os,const CowBasicString<T>&rhs);
		private:
			void IncreaseRefCount() const{ ++(*(int*)(_pstr-4)); }
			void DecreaseRefCount() const{ --(*(int*)(_pstr-4)); }
			void detach(){
				DecreaseRefCount();
				if(0==RefCount()){
					delete [] (_pstr-4);
					_pstr=NULL;
				}
			}

		private:
			Pointer _pstr;
	};
	template<typename T>
		CowBasicString<T>::CowBasicString()
		:_pstr(new T[1+4]())//init 0
		{
			cout<<"CowBasicString()"<<endl;
			_pstr+=4;
			IncreaseRefCount();
//			++(*(int*)(_pstr-4));
		}
#if 1
	template<typename T>
		CowBasicString<T>::CowBasicString(const std::basic_string<T>&rhs)
		:_pstr(new T[4+rhs.size()+1]())
		{
			_pstr+=4;
			strcpy(_pstr,rhs.c_str());
			IncreaseRefCount();
		}
#endif
	template<typename T>
		CowBasicString<T>::CowBasicString(const char*p)
		:_pstr(new T[4+strlen(p)+1]())
		{
			_pstr+=4;
			strcpy(_pstr,p);
			IncreaseRefCount();
		}
	template<typename T>
		CowBasicString<T>::CowBasicString(const char&rhs)
		:_pstr(new T[2+4]())//init 0
		{
			cout<<"CowBasicString(const char&)"<<endl;
			_pstr+=4;
			IncreaseRefCount();
			*_pstr=rhs;
		}
	template<typename T>
		CowBasicString<T>::CowBasicString(const CowBasicString&rhs)
		:_pstr(rhs._pstr)
		{
			cout<<"CowBasicString(const CowBasicString&)"<<endl;
			IncreaseRefCount();
		}
	template<typename T>
			CowBasicString<T>&CowBasicString<T>::operator=(const CowBasicString&rhs){
				if(this!=&rhs){
//					T *tmp=new T[size()+4]();
//					tmp+=4;
//					strcpy(tmp,rhs._pstr);
//					delete [] (_pstr-4);
					detach();
					_pstr=rhs._pstr;
					IncreaseRefCount();
				}
				return *this;
			}
	template<typename T>
			T& CowBasicString<T>::operator[](const size_t &index)const{
					return *(_pstr+index);
			}
	template<typename T>
			T& CowBasicString<T>::operator[](const size_t &index){
				if(index>=size()) {
					static char tmp= '\0';
					perror("index >= size()");
					return tmp;
				}
				if(RefCount()>1){
				//deep copy
					T *tmp=new T[size()+4]();
					tmp+=4;
					strcpy(tmp,_pstr);
					detach();
					_pstr=tmp;
					IncreaseRefCount();
				}
					return *(_pstr+index);
			}
			
#if 0
	template<typename T>
	std::ostream& operator<<(std::ostream&os,const CowBasicString<T>&rhs){
		os<<rhs._pstr;
		return os;
	}
#endif
	template<typename T>
		CowBasicString<T>::~CowBasicString(){
			cout<<"~CowBasicString()"<<endl;
			detach();
#if 0
			if(0==RefCount()){
//				delete this;
				delete [] (_pstr-1);
				_pstr=nullptr;
			}
#endif
		}
}

#endif
