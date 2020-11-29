///
//
/// @file    set.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-04-05 03:40:38
///

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <functional>
#include <utility>
using std::cout;
using std::endl;
using std::set;
using std::multiset;
using std::map;
using std::multimap;
using std::string;
using std::vector;
using std::less;
using std::greater;
using std::pair;
int test()
{
	set<string> s1;//way1
	//s1.push_back("hello");
	set<string> s2={"hello"};
	for(auto &elem :s2)
	{
		cout<<elem<<endl;
	}
	return 0;
}

void test1()
{
	//set容器的使用: 关键字不允许重复，按照关键字排序
	int sz[9] = {2, 1, 3, 5, 4, 6, 3, 5, 6};	//定义int型数组，数组名相当于指针（迭代器）
	vector<int > v={10,30,40,20,50};
	set<int,less<int>> s1;//way1

	set<int,less<int> > v1(v.begin(),v.begin()+5); //way2
	//error: vector<int> v1(v.begin(),v.begin()+5,less<int>); //way2
	for(auto &elem:v1) {cout<<elem<<" ";} cout<<endl;
	set<int> A(sz, sz + 9);	//way2			//将迭代器区间作为参数创建容器对象A
	set<int> B(v.begin(),v.begin()+2);//way2				//将迭代器区间作为参数创建容器对象A
	set<int,less<int>>C(B);//way3
	cout<<"this is C"<<endl;
	for(auto &elem:C) {cout<<elem<<" ";}
	cout<<endl;
	cout<<"this is B"<<endl;
	for(auto &elem:B) {cout<<elem<<" ";}
	cout << A.size() << endl;			//输出A中元素个数

	set<int>::iterator it = A.begin();	//创建set<int>::iterator迭代器it，指向A头部
	while (it != A.end())				//输出全部元素
	{
		cout << (*it) << "  ";
		it++;
	}
	cout << endl;

	//	getchar();
}

void test2()
{
	//	multiset容器的使用: 关键字允许重复，按照关键字排序

	int sz[9] = {2, 1, 3, 5, 4, 6, 3, 5, 6};	//定义int型数组，数组名相当于指针（迭代器）
	multiset<int,greater<int>> A(sz, sz + 9);				//将迭代器区间作为参数创建容器对象A
	//multiset<int> A(sz, sz + 9);				//将迭代器区间作为参数创建容器对象A
	//multiset<int,less<int>> A(sz, sz + 9);				//将迭代器区间作为参数创建容器对象A
	set<int> B(sz, sz + 9);				//将迭代器区间作为参数创建容器对象A
	cout << A.size() << endl;					//输出A中元素个数
	for(auto &elem: B) {cout<<elem<<" ";}
	cout<<endl<<"this is A:"<<endl;
	multiset<int>::iterator it = A.begin();		//创建set<int>::iterator迭代器it，指向A头部
	while (it != A.end())						//输出全部元素
	{
		cout << (*it) << "  ";
		it++;
	}
	cout << endl;

	getchar();


}
void test3()
{
#if 0
	pair<const char,string> p('a',"Hello");
	//error: p.first='A';
	cout<<p.first<<' '<<p.second<<endl;
	cout<<endl;
	map<const char, string, greater<string>> m1;//way1
	pair<int,string> sz[]={ pair<int,string>(1,"shanghai"),pair<int,string>(2,"beijing"),pair<int,string>(3,"shenzheng")};
	//for(auto &elem : sz) {cout<<elem.first<<' '<<elem.second<<'\n';}
	map<int,string> m2(sz,sz+2);//way3
	cout<<"map2\n";
	for(auto &elem :m2){ cout<<elem.first<<' '<<elem.second<<endl;}
	map<int,string> m3(m2);
	cout<<"map3"<<endl;
	for(auto &elem :m3){ cout<<elem.first<<' '<<elem.second<<endl;}
	//map<char,string> m3(m2);
	cout<<"------------------------------"<<endl;
//	cout<<m3[4]<<endl;
	cout<<"------------------------------"<<endl;
	for(auto it=m3.begin();it!=m3.end();++it)
	{
		cout<<(*it).first<<' '<<(*it).second<<endl;
	}
	for(map<int,string>::iterator it=m3.begin();it!=m3.end();++it)
	{
		cout<<(*it).first<<' '<<(*it).second<<endl;
	}
	cout<<"------------------------------"<<endl;



	//insert
	pair<map<int,string>::iterator, bool> p1 = m3.insert(pair<int, string>(4,"Hongkong"));
	//auto p1 = m3.insert(pair<int, string>(4,"Hongkong"));
	for(auto &elem :m3){ cout<<elem.first<<' '<<elem.second<<endl;}
//	cout<<*(p1.first)<<' '<<p1.second<<endl;	
	auto p2 =	m3.insert(std::make_pair(4,"taiwan"));
	cout<<"------------------------------"<<endl;

	for(auto &elem :m3){ cout<<elem.first<<' '<<elem.second<<endl;}
	if(p1.second)
	{
		cout<<"seccessful"<<endl;
		cout<<(*(p1.first)).first<<' '<<(*(p1.first)).second<<endl;
	}
	cout<<"------------------------------"<<endl;
	if(p2.second)
		cout<<(*(p2.first)).first<<' '<<(*(p2.first)).second<<endl;
	else{ 
		cout<<"failure"<<endl;
	//error:	cout<<(p2.first)->first<<' '<<(*(p2.first)).second<<endl;
		cout<<(*(p2.first)).first<<' '<<(*(p2.first)).second<<endl;
	}
	for(auto &elem :m3){ cout<<elem.first<<' '<<elem.second<<endl;}
	//insert 2
	//auto::value compare;
	//map<int,string>::value compare;
	map<int,string,std::less<string>> m5(m3.begin(),m3.end());
	for(auto &elem:m5) {cout<<elem.first<<' '<<elem.second<<endl;}
#endif
	map<int,string>::value_type a=std::make_pair(1,"hello");
	map<int,string> M={a};
	map<int,string>::key_type b= 3;
	map<int,string>::mapped_type c= "Hello";
	cout<<b<<endl;
	cout<<c<<endl;
	cout<<a.first<<' '<<a.second<<endl;
	auto it = M.begin();
	cout<<it->first<<' '<<it->second<<endl;
	cout<<(*it).first<<' '<<(*it).second<<endl;
}

int main()
{
	test3();
	return 0;
}
