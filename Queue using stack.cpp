#include<iostream>
using namespace std;
class node{
	node *nextnode;
	int value;
	public:
		node()
		{
			nextnode=0;
			value=0;
		}
		void setnextnode(node *nextnode)
		{
			this->nextnode=nextnode;
		}
		void setvalue(int value)
		{
			this->value=value;
		}
		int getvalue()
		{
			return value;
		}
		node *getnextnode()
		{
			return nextnode;
		}
};
class queu
{
     public:
	     node *front;
		 node *rear;
		 node *newnode;
		 int size;
	queu()
	{
		front = rear= newnode =0;
		size=0;
		}	
  	void enqueu(int v)
  	{
  		newnode= new node();
  		newnode->setvalue(v);
  		newnode->setnextnode(0);
  		if(size==0)
  		{
  			front = newnode;
  			rear = newnode;
  			size++;
		  }
		 else
		 {
		 	newnode->setnextnode(front);
		 	front = newnode;
		 	size++;
		  }	
	  }
	void deque()
	{
		node *tmp=front;
		while(tmp->getnextnode()!=rear)
		{
			tmp=tmp->getnextnode();
		}
		rear = tmp;
		delete tmp->getnextnode();
		rear->setnextnode(0);
		size--;
	}
	void print()
	{
		node *tmp = front;
		while(tmp!=0)
		{
			cout<<tmp->getvalue()<<"->";
			tmp=tmp->getnextnode();
		}
	}
};
class stack{
	node *newnode;
	node *top;
	int size;
	public:
		stack()
		{
			newnode=top=0;
			size=0;
		}
    void push(int v)
    {
    	newnode = new node();
    	newnode->setvalue(v);
    	if(size==0)
    	{
    		newnode->setnextnode(0);
    		top=newnode;
    		size++;
		}
		else
		{
			newnode->setnextnode(top);
			top=newnode;
			size++;
		}
	}
	int pop()
	{
	    node *tmp=top;
		int v=top->getvalue();
		top=top->getnextnode();
		delete tmp;
		size--;
		return v;
	}
	void print()
	{
		node *tmp = top;
		while(tmp!=0)
		{
			cout<<tmp->getvalue()<<endl;
			tmp=tmp->getnextnode();
		}
	}
};
int main()
{
    queu q1;
	stack s1,s2;
	s1.push(1);
	s1.push(2);	
	s1.push(3);	
	s1.push(4);
	s1.print();
	s2.push(s1.pop());
	s2.push(s1.pop());
	s2.push(s1.pop());
	s2.push(s1.pop());
	s2.print();
	q1.enqueu(s2.pop());
	q1.enqueu(s2.pop());
	q1.enqueu(s2.pop());
	q1.enqueu(s2.pop());
	q1.print();
	return 0;	 
}
