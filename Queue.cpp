#include<iostream>
using namespace std;;

class node{
	int info;
	node *link;
	public:
		node(){
			info=0;
			link=NULL;
		}
		void setInfo(int d)
		{
			info =d;
		}
		int getInfo()
		{
			return info;
		}
		void setLink(node *ptr)
		{
			link=ptr;
		}
		node* getLink()
		{
			return link;
		}
		
};
class Queue{
	node *head;
	node *tail;
	public:
		Queue()
		{
			head=NULL;
			tail=NULL;
		}
		void enQueue(int x)
		{
			node *temp = new node;
			temp->setLink(0);
			temp->setInfo(x);
			if(head==NULL)
			{
				tail=temp;
				head=temp;

			}
			else
			{
				tail->setLink(temp);
				tail=temp;
			}
				
			temp=NULL;
			delete temp;
		}
		void deQueue()
		{
			node *temp=head;
			if(head==NULL)
			{
				cout<<"Queue is Empty!!!../n";

			}
			else
			{
				head=head->getLink();
				delete temp;
				cout<<"Value is removed."<<endl;
			}
		}
		void print()
		{
			node *temp = head;
			while(temp!=NULL)
			{
				cout<<temp->getInfo()<<"->";
				temp= temp->getLink();
				
			}
		}
};
int main()
{
	Queue q;
	q.enQueue(24);
	q.enQueue(48);
	q.enQueue(21);
	q.deQueue();
	q.print();
}
