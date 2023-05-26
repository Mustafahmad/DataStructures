#include<iostream>
using namespace std;

class dNode
{
	private:
		int data;
		dNode *next, *prev;
	public:
		dNode(int d=0)
		{
			setData(d);//data=d;
			next=prev=NULL;
		}
		void setData(int x)
		{
			data=x;
		}
		int getData()
		{
			return data;
		}
		void setNext(dNode *ptr)
		{
			next=ptr;
		}
		dNode* getNext()
		{
			return next;
		}
		void setPrev(dNode *ptr)
		{
			prev=ptr;
		}
		dNode* getPrev()
		{
			return prev;
		}
};

class doublyLinkedList
{
	private:
		dNode *start;
	public:
		doublyLinkedList()
		{
			start=NULL;
		}
		void insert(int d)//addLast
		{
			if(start==NULL)
				start=new dNode(d);//create a new node using start pointer and set it's data part
			else
			{
				dNode *temp=new dNode;//create a new node using temp pointer
				temp->setData(d);//set it's data part
				//set next of older/previuos last node towards this node
				dNode *current=start;
				while(current->getNext()!=NULL)
				{
					current=current->getNext();
				}
				current->setNext(temp);
				//set the prev pointer of this node towards older last
				temp->setPrev(current);
				current=temp=NULL;//remove temp pointer
				delete temp;
				delete current;
			}
		}
		void print()
		{
			dNode *curr=start;
			while(curr!=NULL)
			{
				cout<<curr->getData()<<", ";
				curr=curr->getNext();
			}
			cout<<"\n";
		}
		void reversePrint()
		{
			dNode *curr=start;
			while(curr->getNext()!=NULL)
			{
				curr=curr->getNext();
			}
			while(curr!=NULL)
			{
				cout<<curr->getData()<<", ";
				curr=curr->getPrev();
			}
			cout<<"\n";
		}
};

int main()
{
	doublyLinkedList list1;
	list1.insert(12);
	list1.insert(16);
	list1.insert(78);
	list1.insert(67);
	list1.print();//12, 16, 78, 67, 
	list1.reversePrint();//67, 78, 16, 12, 
	return 0;
}
