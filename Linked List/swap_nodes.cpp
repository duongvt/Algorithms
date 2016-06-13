#include<stdio.h>
#include<stdlib.h>
 
struct node
{
	int data;
	struct node* next;
};

struct node* insert(struct node* head,int x)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	
	if(head==NULL)
	{
		head=temp;
		return head;
	}
	
	struct node* temp2=head;
	while(temp2->next!=NULL)
	{
		temp2=temp2->next;
	}
	temp2->next=temp;
	return head;
}

void print_list(struct node* head)
{
	struct node* temp=head;
	printf("List: ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

struct node* swap_nodes(struct node* head,int x,int y)
{
	if(x==y)
	{
		printf("Can't be swapped\n");
		return head;
	}
	struct node *curr_node1=head,*prev_node1=NULL;
	while(curr_node1&&curr_node1->data!=x)
	{
		prev_node1=curr_node1;
		curr_node1=curr_node1->next;
	}
	
	
	struct node *curr_node2=head,*prev_node2=NULL;
	while(curr_node2&&curr_node2->data!=y)
	{
		prev_node2=curr_node2;
		curr_node2=curr_node2->next;
	}
	
	if(curr_node1==NULL||curr_node2==NULL)
	{
		printf("Can't be swapped\n");
		return head;
	}
	
	if(prev_node1!=NULL) prev_node1->next=curr_node2;
	else head=curr_node2;
	
	if(prev_node2!=NULL) prev_node2->next=curr_node1;
	else head=curr_node1;
	
	struct node* temp=curr_node2->next;
	curr_node2->next=curr_node1->next;
	curr_node1->next=temp;
	return head;
}

int main()
{
	struct node* head=NULL;
	int x,y,n;
	
	while(1)
	{
		printf("Press 1 to insert a node to the end of linked list\n");
		printf("Press 2 to swap 2 nodes\n");
		printf("Press 3 to display the list\n");
		printf("Press 4 to exit\n");
		scanf("%d",&n);
		
		switch(n)
		{
			case 1: printf("Enter the element to insert in list\n");
					scanf("%d",&x);
					head=insert(head,x);
					printf("%d insert successfully\n",x);
					break;
					
			case 2: printf("Enter the 2 nodes to swap\n");
					scanf("%d%d",&x,&y);
					head=swap_nodes(head,x,y);
					break;
			
			case 3: print_list(head);
					break;
					
			case 4: exit(1);
					break;
				
		    default:printf("Please enter a valid input\n");
		    		break;
		}
	}
	return 0;
}
