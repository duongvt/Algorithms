#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* insert_at_head(struct node* head,int x)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	
	if(head==NULL)
	{
		head=temp;
		return head;
	}
	head->left=temp;
	temp->right=head;
	head=temp;
	
	return head;
}

struct node* insert_at_end(struct node* head,int x)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	
	struct node* temp2=head;
	
	while(temp2->right!=NULL)
	{
		temp2=temp2->right;
	}
	temp2->right=temp;
	temp->left=temp2;
	temp->right=NULL;
	
	return head;
}

struct node* insert_at_nth(struct node* head,int x,int y)
{
	int i;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	
	if(head==NULL)
	{
		head=temp;
	}
	else if(y==1)
	{
		head->left=temp;
		temp->right=head;
		head=temp;
	}
	else
	{
		struct node* temp2=head;
		for(i=0;i<y-2;i++)
		{
			temp2=temp2->right;
		}
		temp->right=temp2->right;
		temp->left=temp2;
		temp2->right=temp;
	}
	return head;
}

void print_list(struct node* head)
{
	struct node* temp=head;
	printf("List: ");
	
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->right;
	}
	printf("\n");
}

int main()
{
	struct node* head=NULL;
	int x,y,n;
	
	while(1)
	{
		printf("Press 1 to insert a node at the beginning\n");
		printf("Press 2 to insert a node at the end\n");
		printf("Press 3 to insert a ndoe at the nth position\n");
		printf("Press 4 to display the list\n");
		printf("Press 5 to exit\n");
		scanf("%d",&n);
		
		switch(n)
		{
			case 1: printf("Enter the element to insert\n");
					scanf("%d",&x);
					head=insert_at_head(head,x);
					printf("%d inserted sucessfully\n",x);
					break;
					
			case 2: printf("Enter the element to insert\n");
					scanf("%d",&x);
					head=insert_at_end(head,x);
					printf("%d inserted sucessfully\n",x);
					break;
					
			case 3: printf("Enter the element to insert\n");
					scanf("%d",&x);
					printf("At which position you want to insert\n");
					scanf("%d",&y);
					head=insert_at_nth(head,x,y);
					printf("%d inserted successfully\n");
					break;
					
			case 4: print_list(head);
					break;
					
			case 5: exit(1);
					break;
			
			default: printf("Please enter a valid input\n");
			         break;
		}
	}
	return 0;
}
