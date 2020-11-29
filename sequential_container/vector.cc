 ///
 /// @file    vector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-05 00:09:23
 ///
 
#include <iostream>
#include <vector>
#include <deque>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::deque;
using std::list;

int test1(void)
{
//error:	vector<auto> v1 = {1,2,3,4,5,6};
	vector<int> v1 = {1,2,3,4,5,6};
	for(auto &elem: v1)
	{
		cout<<elem<<endl;

	}
	for(vector<int>::iterator ite = v1.begin(); ite!=v1.end(); ++ite)
	{
		cout<<*ite<<endl;
	}
	for(auto i=0;i< v1.size();++i)
	{
		cout<<v1.at(i)<<endl;
		cout<<v1[i]<<endl;
	}
}
int test2()
{
	vector<string> vs1;//way1
	vector<string> vs2(10);//way2
	vector<int> v2(10);//way2
	vector<string> vs3(10,"hi");//way3
	vector<string> vs4= vs3;//way4
	vs3.push_back("world");
	vector<string> vs5(vs3);//way4
	for(auto &elem : vs5)
	{
		cout<<elem<<endl;
	}
	cout<<vs2.size()<<endl;
	cout<<vs2.capacity()<<endl;
	vs1.push_back("hello");
	cout<<vs1.size()<<endl;
	cout<<vs1.capacity()<<endl;
}
int test3()
{
	//way5:
	int sz[5]={11,2,3,4,45};
	vector<int> obV(sz, sz+5);
	list<int> obL(sz, sz+5);
	deque<int> obD(sz, sz+5);
	for(auto &elem : obV)
	{
		cout<<elem<<endl;
	}
	for(auto it= obV.begin();it!=obV.end();++it)
	{
		cout<<*it<<endl;
	}
	cout<<"-------------------"<<endl;
	for(auto it= obL.begin();it!=obL.end();++it)
	{
		cout<<*it<<endl;
	}
	for(auto &elem : obL)
	{
		cout<<elem<<endl;
	}
	cout<<"-------------------"<<endl;
	for(int i=0; i<obD.size();++i)
	{
		//cout<<obD[i]<endl;
		
	//	cout<<obD.at(i)<endl;
	}
	for(auto it= obD.begin();it!=obD.end();++it)
	{
		cout<<*it<<endl;
	}
	for(auto &elem : obD)
	{
		cout<<elem<<endl;
	}
	return 0;
}

void test4()
{
	vector<int> v2(5,11);
	cout<<v2.size()<<endl;
	cout<<v2.capacity()<<endl;
	vector<int> v3(3,111);
	vector<int> v4(4,111);
	if(v4==v3)
		cout<<"true"<<endl;
	//v2.swap(v3);
	cout<<v2.size()<<endl;
	cout<<v2.capacity()<<endl;
	for(auto &elem : v2)
	{
		cout<<elem<<" ";
	}
	cout<<endl;
}

void test5()
{
	vector<string> v1(4,"hello");
	deque<string> d1(4,"hi");
	list<string> l1(4,"world");
	
	v1.push_back("world");
//	int ret= v1.pop_back();
	cout<<v1.front()<<endl;
	cout<<v1.back()<<endl;
	cout<<"-----------------------"<<endl;
	d1.push_back("hello");
	d1.push_front("HELLO");
	d1.pop_back();
	d1.pop_front();
	cout<<d1.front()<<endl;
	cout<<d1.back()<<endl;
	cout<<"-----------------------"<<endl;
	l1.push_back("cheng");
	l1.push_front("WANG");
	l1.pop_back();
	l1.pop_front();
	cout<<l1.front()<<endl;
	cout<<l1.back()<<endl;
}
void test6()
{
	vector<string> v1(4,"hello");
	deque<string> d1(4,"hi");
	list<string> l1(4,"world");

	auto it = v1.insert(v1.begin()+2, "HELLO");
	for(auto &elem:v1){ cout<<elem<<" ";} cout<<endl;

	v1.insert(it,3, "Hello");
	for(auto &elem:v1){ cout<<elem<<" ";} cout<<endl;
	v1.erase(it);
	for(auto &elem:v1){ cout<<elem<<" ";}
	cout<<endl;
	v1.erase(it,it+2);
	for(auto &elem:v1){ cout<<elem<<" ";}
	cout<<"------------------------"<<endl;
	d1.insert(d1.begin(),"HI"); 
	auto it1 = l1.insert(l1.begin(), "HELLO");
	for(auto &elem:l1){ cout<<elem<<" ";}
	cout<<endl;
	l1.erase(it1);
	string a[]={"zhang","wang","liu"};
	//error: l1.insert(it1,a,a+3);
	//error: l1.insert(it1,v1.begin()+1,v1.begin()+3);
	for(auto &elem:l1){ cout<<elem<<" ";}
	cout<<endl;

}

	
int main(void)
{
	test6();
	return 0;
}
