#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* push(node* head,int data)
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->next=NULL;

	if(head==NULL)
	{
		head=newnode;
		return head;
	}

	newnode->next=head;
	head=newnode;
	return head;
}


node* pop(node* head)
{
	if(head==NULL) return NULL;

	node* temp=head;
	head=temp->next;
	delete temp;
	return head;
}


void top(node* head)
{
	if(head==NULL) cout<<"Stack empty"<<endl;
	else cout<<head->data<<endl;
}


bool isEmpty(node* head)
{
	if(head==NULL) return 0;
	else return 1;
}

void print(node* head)
{
	if(head==NULL)
	{
		cout<<"Stack empty"<<endl;
		return;
	}
	node* temp=head;

	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	node* head=NULL;
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
					head=push(head,x);
					cout<<x<<" pushed to stack"<<endl;
					break;

			case 2: head=pop(head);
					if(!isEmpty(head)) cout<<"Element popped"<<endl;
					break;

			case 3: top(head);
					break;

			case 4:	z=isEmpty(head);
					if(z==0) cout<<"Stack empty"<<endl;
					else cout<<"Stack not empty"<<endl;
					break;

			case 5: print(head);
					break;

			case 6: exit(1);
					break;
		}
	}
return 0;
}



