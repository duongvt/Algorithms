#include<bits/stdc++.h>
#define MAXSIZE 1000
using namespace std;


int a[MAXSIZE],top=-1;


void push(int data)
{
	if(top==MAXSIZE-1)
	{
		cout<<"Overflow"<<endl;
		return;
	}

	a[++top]=data;
}


void pop()
{
	if(top==-1)
	{
		cout<<"Stack empty"<<endl;
	}
	top--;
}


void Top()
{
	if(top==-1) 
	{
		cout<<"Stack empty"<<endl;
		return;
	}
	cout<<a[top]<<endl;
}

bool isEmpty()
{
	if(top==-1) return 0;
	else return 1;

}


void Print()
{
	if(top==-1)
	{
		cout<<"Stack empty"<<endl;
		return;
	}

	int i;

	for(i=top;i>=0;i--)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int x,y,n;
	bool z;

	while(1)
	{
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.Top element"<<endl;
		cout<<"4.IsEmpty"<<endl;
		cout<<"5.Print"<<endl;
		cout<<"6.Exit"<<endl;

		cin>>n;

		switch(n)
		{
			case 1: cout<<"Enter element to push"<<endl;
					cin>>x;
					push(x);
					cout<<x<<" pushed to stack"<<endl;
					break;

			case 2: pop();
					if(!isEmpty()) cout<<"Element popped"<<endl;
					break;

			case 3: Top();
					break;

			case 4: isEmpty();
					z=isEmpty();
					if(z==0) cout<<"Stack empty"<<endl;
					else cout<<"Stack not empty"<<endl;
					break;

			case 5: Print();
					break;

			case 6: exit(1);
					break;
		}
	}
return 0;
}
