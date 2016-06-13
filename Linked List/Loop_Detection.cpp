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

void create_cycle(struct node* head)
{
	struct node* temp=head;
	
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head;
}

int detect_cycle(struct node* head)
{
	struct node *hare=head,*tortoise=head;
	
	while(hare->next!=NULL)
	{
		tortoise=tortoise->next;
		hare=hare->next->next;
		
		if(tortoise==hare) return 1;
	}
	return 0;
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

int main()
{
	struct node* head=NULL;
	int x,y,n;
	
	while(1)
	{
		printf("Press 1 to insert a node at the end of linked list\n");
		printf("Press 2 to create a cycle in the linked list\n");
		printf("Press 3 to detect a cycle in the linked list\n");
		printf("Press 4 to print the list\n");
		printf("Press 5 to exit\n");
		scanf("%d",&n);
		
		switch(n)
		{
			case 1: printf("Enter the element to insert\n");
					scanf("%d",&x);
					head=insert(head,x);
					printf("%d inserted successfully\n",x);
					break;
					
			case 2: create_cycle(head);
					printf("Loop created\n");
					break;
					
			case 3: x=detect_cycle(head);
					if(x==1) printf("There is a cycle in list\n");
					else printf("No cycle in list\n");
					break;
					
		    case 4: print_list(head);
		    		break;
		    		
		    case 5: exit(1);
		    		break;
		    		
		    default:printf("Please enter a valid input\n");
		    		break;
		}
	}
	return 0;
}
