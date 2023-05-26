#include<iostream>
#include<cmath>
using namespace std;

class node
{
	private:
		int info;
		node *link;
	public:
		node(int d)
		{
			info=d;
			link=NULL;	
		}	
		void setInfo(int x)
		{
			info=x;
		}
		void setLink(node *p)
		{
			link=p;
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

class linkedList
{
	private:
		node *start;
	public:
		linkedList()
		{
			start=NULL;	
		}	
		void insert(int d, int key);
		
		void insert(int d)
		{
			//create new node using list pointer and set its datapart
			//pointer=new type;
			if(start==NULL)
				start=new node(d);
			else
			{
				node *temp=new node(d);//create new node using temp pointer
				//set it's data/info part
				node *temp1=start;
				while(temp1->getLink()!=NULL)
					temp1=temp1->getLink();//set link of previous/last node towards this node
				temp1->setLink(temp);
				
				temp1=temp=NULL;
				delete temp1;
				delete temp;//remove temp pointer	
			}	
		}
	int getLength()
	{
		node *temp=start;
		int length=0;
		while(temp!=NULL)
		{
			length++;
			temp=temp->getLink();
		}
		return length;
	}
	
	int getMid()
	{
		int mid=ceil(getLength()/2.0);
		node *temp=start;
		for(int i=1; i<=mid; i++)
			temp=temp->getLink();
		return temp->getInfo();
	}
	int getMid2()//using one loop
	{
		node *t1, *t2;
		t1=t2=start;
		while(t2->getLink()!=NULL)//||t2!=NULL)
		{
			t1=t1->getLink();
			t2=t2->getLink();
			if(t2->getLink()!=NULL)
				t2=t2->getLink();
		}
		int temp=t1->getInfo();
		delete t1;
		delete t2;
		return temp;
	}


	void print()
	{
		node *current=start;
		while(current!=NULL){
			cout<<current->getInfo()<<"->";
			current=current->getLink();//set link of previous/last node towards this node
		}
		cout<<"NULL\n";
	}		
};



int main()
{
	linkedList list1, list2;
	list1.insert(18);	
	list1.insert(32);
	list1.insert(23);
	list1.insert(16);	
	list1.insert(43);
	list1.insert(87);
//	list1.insert(25);	
//	list1.insert(44);	
	list1.print();
	list2.print();
	cout<<list1.getMid()<<endl;
	cout<<list1.getMid2();
	return 0;
}

