#include<iostream>
using namespace std;

/*define and test a user defined type/class named 
array having an integer array of size 5 as a data 
member. define a constructor function for this class
also define a member function to store values in 
array, define another member function which displays
the elements stored in the array*/

//stack is a datastructure in which insertion(push)
//and removal(pop) is performed from one end only 
//which is called as top(end)
//stack basic property: top
//basic operations: push/pop
//working principle: LIFO/FILO

class dStack
{
	private:
		int *arr;	
		int top, size;
	public:
		dStack(int s)
		{
			size=s;
			//pointerName=new dataType[size];
			arr=new int[size]; 
			for(int i=0; i<size; i++)
				arr[i]=0;
			top=-1;
		}
		void push(int x)
		{
			if(!isFull())
			{
				top++;
				arr[top]=x;
			}
			else
				cout<<"Stack is Full!...\n";
		}	
		int pop()
		{
			int temp=0;
			if(isEmpty())
				cout<<"Stack is Empty!...\n";
			else
			{
				temp=arr[top];
				arr[top]=0;
				top--;
			}
			return temp;
		}
		bool isEmpty()
		{
			if(top==-1)
				return true;
			else
				return false;
		}
		bool isFull()
		{
			if(top==size-1)
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
				cout<<"Elements of stack: \n";
				for	(int i=top; i>=0; i--)
				{
					cout<<arr[i]<<endl;
				}
			}
		}	
	~dStack()
	{
		cout<<"Object is Being destroyed!...\n";
		delete []arr;
	}
};

int main()
{
	dStack obj(5), obj2(10);
//	obj.pop();
	obj.push(50);
	obj.push(40);
	obj.push(30);
	obj.push(20);
	obj.push(10);
//	obj.push(5);
	obj.print();
	obj.pop();
	obj.print();
	return 0;
}

