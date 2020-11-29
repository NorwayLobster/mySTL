///
/// @file    queue.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-03-28 23:42:38
///
// 未完成 
#include <iostream>
using std::cout;
using std::endl;
typedef struct tagnode
{
	int data;
	struct tagnode * next;
}Node;
template<class T>
class queue

class queue
{
	public:
		void push(int);
		void print();
		void pop();
		int  top();
		int  empty();
		bool full();
		queue()
			:head(NULL)
			 ,size(0)
	{
	};
		~queue()
		{
			cout<<"~queue"<<endl;
		};
	private:
		Node * head;
		int size;
};

void queue:: push(int data)
{
	cout<<"push()"<<endl;
	Node * p =NULL;
	Node * ppre =NULL;
	Node * pcur=NULL;
	if(NULL==head)
	{
		p = new Node[sizeof(Node)]();
		p->data=data;
		p->next=NULL;
		head = p;
		size=1;
	}
	else 
	{
		//ppre=pcur;
		//	pcur=pcur->next;
		p = new Node[sizeof(Node)]();
		p->data=data;
		p->next= head;
		head = p;
		++size;
	}
}	
void queue:: pop()
{
	cout<<"pop()"<<endl;
	Node *p= NULL;
	if(NULL==head)
	{
		cout<<"it is already empty"<<endl;
	}
	else if(NULL==head->next)
	{
		cout<<" -1 pop()"<<endl;
		delete head;
		head=NULL;
		size=0;
	}
	else 
	{
		cout<<" -x pop()"<<endl;
		p = head;
		head = head->next;
		--size;
		delete p;	
	}
}

int queue:: top()
{
	if(NULL!=head)
		return head->data;
	else 
	{
		cout<<"it is empty"<<endl;
		return 0;
	}
}

int  queue:: empty()
{
	return size;
}
bool queue:: full()
{
	bool a;
	if(10==size)
		a=1;
	else 
		a=0;
	return a;
}
void queue:: print()
{
	Node *p=head;
	cout<<"size="<<size<<endl;
	while(NULL!=p)
	{

		cout<<p->data;
		p=p->next;
		if(NULL!=p)
		{
			cout<<" ";
		}
	}
	cout<<endl;
}

int main(void)
{
	queue s1;
	cout<<"-------------------------"<<endl;
	s1.push(1);
	s1.print();
	cout<<"-------------------------"<<endl;
	s1.push(2);
	s1.print();
	cout<<"-------------------------"<<endl;
	if(s1.empty())
	{
		cout<<"not empty "<<endl;
	}
	else 
		cout<<"empty"<<endl;
	cout<<"-------------------------"<<endl;
	s1.pop();
	s1.print();
	cout<<"-------------------------"<<endl;
	cout<<s1.top()<<endl;
	cout<<"-------------------------"<<endl;
	s1.pop();
	s1.print();
	cout<<"-------------------------"<<endl;
	s1.pop();
	s1.print();
	cout<<"-------------------------"<<endl;
	cout<<s1.top()<<endl;
	cout<<"-------------------------"<<endl;
	return 0;
}
