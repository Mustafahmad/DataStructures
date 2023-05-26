#include<iostream>
using namespace std;

class node
{
	private:
		int info;
		node* link;
	public:
		node(int d=0)
		{
			info=d;
			link=NULL;	
		}	
		void setInfo(int d)
		{
			info=d;
		}
		void setLink(node *ptr)
		{
			link=ptr;
		}
		int getInfo()
		{
			return info;
		}
		node* getLink()
		{
			return link;
		}
};

class stack
{
	private:
		node* top;
	public:
		stack()
		{
			top=NULL;
		}
		void push(int d)
		{
			if(isEmpty())
				top=new node(d);
			else
			{
				node *temp=new node;//create a new node using temp pointer
				temp->setInfo(d);//set it's data part
				temp->setLink(top);//set it's link towards older/previous top
				top=temp;//point top towards this/newly node
				temp=NULL;//remove temp pointer
				delete temp;
			}
		}		
		int pop()
		{
			int t=-1;
			if(isEmpty())//check whether stack is empty or not?
			//in case stack is empty
				cout<<"Stack is Empty!...\n";//display; the stack is empty
			else//in case stack is not empty
				//perform pop operation
			{	node *temp=top;//create and point temp pointer towards top
				top=top->getLink();//move top to next node
				temp->setLink(NULL);//remove link of current/temp node
				t=temp->getInfo();//retain data/info part
				delete temp;//delete temp/current node
			}
			return t;//return data/info part			
		}	
		bool isEmpty()
		{
			if(top==NULL)
				return true;
			else
				return false;
		}
		void print()
		{
			if(isEmpty())
				cout<<"Stack is Empty!...\n";
			else
			{
				node *curr=top;
				cout<<"Elements of stack:\n";
				while(curr!=NULL)
				{
					cout<<curr->getInfo()<<endl;
					curr=curr->getLink();
				}
			}
		}
};

int main()
{
	stack st1;
	st1.print();
	st1.push(12);
	st1.push(17);
	st1.push(20);
	st1.print();
	cout<<"The Popped Value: "<<st1.pop()<<endl;
	st1.push(5);
	st1.push(89);
	st1.print();
	return 0;
}

