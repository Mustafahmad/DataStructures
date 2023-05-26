#include<iostream>
using namespace std;

class stack
{
	int arr[5];
	int top;
	public:
	stack()
	{
		for (int i=0;i<5;i++){
			arr[i]=0;
			top=-1;
		}
	}
	void menu()
	{
		system("cls");
		int num;
		int no;
		cout<<"Enter 1 to push."<<endl;
		cout<<"Enter 2 to pop."<<endl;
		cout<<"Enter 3 to print array."<<endl;
		cout<<"Enter 4 to exit the program.."<<endl;
		cin>>num;
		switch(num)
		{
		case 0:
			cout<<"Enter the correct number!.../n";
			break;
		case 1:
			cout<<"Enter number to push: ";
			cin>>no;
			push(no);
			system("pause>nul");
			menu();
			break;
		case 2:
			pop();
			system("pause>nul");
			menu();
			break;
		case 3:
			print();
			system("pause>nul");
			menu();
			break;
		case 4:
			exit(0); 
		default:
			cout<<"Enter the correct number!.../n";
			break;
	}
	}
	void push(int x)
	{
		if(top>=4)
		{
			cout<<"Stack is full!!"<<endl;
		}
		else
		{
		cout<<"Value "<<x<<" is pushed in the stack."<<endl;	
		arr[++top]=x;
		}
	}
	void pop()
	{
		if (top==-1)
				cout<<"Stack is Empty!...\n";
			else
			cout<<"Value is poped out of stack!!"<<endl;
			arr[top--]=0;
//			top--;
	}
		void print()
		{
			cout<<"Elements of Stack: \n";
			for(int i=top; i>=0; i--)
			{
				cout<<arr[i]<<endl;
			}			
		}
};

int main()
{
	stack s1;
	s1.menu();
	return 0;
}

