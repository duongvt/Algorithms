#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* insert_at_head(struct node* head,int x)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	
	temp->next=head;
	head=temp;
	
	return head;	
}

struct node* insert_at_nth(struct node* head,int x,int y)
{
	int i;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	
	if(y==1)
	{
		temp->next=head;
		head=temp;
		return head;
	}
	
	struct node* temp2=head;
	
	for(i=0;i<y-2;i++)
	{
		temp2=temp2->next;
	}
	temp->next=temp2->next;
	temp2->next=temp;
	return head;
}

struct node* delete_at_head(struct node* head)
{
	if(head==NULL)
	{
		printf("List is empty\n");
		return head;
	}
	
	struct node* temp=head;
	head=temp->next;
	free(temp);
	return head;
}

struct node* delete_at_nth(struct node* head,int x)
{
	struct node* temp=head;
	int i;
	
	if(head==NULL)
	{
		printf("List is empty\n");
		return head;
	}
	
	if(x==1)
	{
		head=temp->next;
		free(temp);
		return head;
	}
	
	for(i=0;i<x-2;i++)
	{
		temp=temp->next;
	}
	
	struct node* temp2=temp->next;
	temp->next=temp2->next;
	free(temp2);
	return head;
}

int find_length(struct node* head)
{
	struct node* temp=head;
	int count=0;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	return count;
}

struct node* reverse_list(struct node* head)
{
	struct node *curr,*prev,*next;
	prev=NULL;
	curr=head;
	
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	head=prev;
	return head;
}

int find_nth_node_from_end(struct node* head,int x)
{
	struct node* temp=head;
	int i;
	
	for(i=0;i<x-1;i++)
	{
		temp=temp->next;
	}
	return temp->data;
}

void print_elements(struct node* head)
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

void print_in_reverse_order(struct node* head)
{
	if(head==NULL) return;
	
	print_in_reverse_order(head->next);
	printf("%d ",head->data);
}

struct node* removedup(struct node* head)
{
	if(head==NULL) return NULL;

	struct node *temp=head,*ne;

	while(temp->next!=NULL)
	{
		ne=temp->next;
		if(temp->data==ne->data)
		{
			temp->next=ne->next;
			delete ne;
			if(temp==NULL) break;
		}
		else
		{
			temp=temp->next;
		}
	}
	return head;
}


struct node* swap_nodes(struct node* head)
{
	if(head==NULL) return NULL;
	struct node *curr=head,*ne;

	while(curr->next->next!=NULL)
	{
		ne=curr->next;
		curr->next=ne->next;
		ne->next=curr;
		curr=curr->next->next;
	}
	return head;
}

int main()
{
	struct node* head=NULL;
	int n,x,y,z,w;
	while(1)
	{
		printf("\n");
		printf("Press 1 to insert a node at beginning of linked list\n");
		printf("Press 2 to insert node at nth position of linked list\n");
		printf("Press 3 to delete a node at beginning of linked list\n");
		printf("Press 4 to delete nth node from the linked list\n");
		printf("Press 5 to find the length of the linked list\n");
		printf("Press 6 to physically reverse the linked list\n");
		printf("Press 7 to print the elements of linked list\n");
		printf("Press 8 to find nth node from the end of linked list\n");
		printf("Press 9 to print linked list in reverse order\n");
		printf("Press 10 to remove duplicates from sorted list\n");
		printf("Press 11 to swap every node\n");
		printf("Press 12 to exit\n");
		
	    scanf("%d",&n);
	    switch(n)
	    {
	    	case 1: printf("Enter the element to insert\n");
	    			scanf("%d",&x);
	    			head=insert_at_head(head,x);
	    			printf("%d successfully inserted\n",x);
	    			break;
	    			
	    	case 2: printf("Enter the element to insert\n");
	    			scanf("%d",&x);
	    			printf("At which position you want to insert the element\n");
	    			scanf("%d",&y);
	    			head=insert_at_nth(head,x,y);
	    			printf("%d successfully inserted at position %d\n",x,y);
	    			break;
	    			
	    	case 3: head=delete_at_head(head);
	    			if(head!=NULL)
	    			{
	    				printf("Successfully deleted\n");
					}
	    			break;
	    			
	    	case 4: printf("Which node you want to delete\n");
	    			scanf("%d",&x);
	    			head=delete_at_nth(head,x);
	    			if(head!=NULL)
	    			{
	    				printf("Successfully deleted\n");	
					}	
	    			break;
	    			
	    	case 5: x=find_length(head);
	    			printf("Length of list: %d\n",x);
	    			break;
	    			
	    	case 6: head=reverse_list(head);
	    			if(head!=NULL)
	    			{
						printf("List reversed\n");	    				
					}
					else printf("List is empty\n");
	    			break;
	    			
	    	case 7: print_elements(head);
	    			break;
	    			
	    	case 8: printf("Which node you want to find from the end\n");
	    			scanf("%d",&x);
	    			y=find_length(head);
	    			if(y==0) printf("List is empty\n");
	    			else
	    			{
	    				z=find_nth_node_from_end(head,(y-x+1));
	    				printf("Element: %d\n",z);
					}
	    			break;
	    			
	    	case 9: printf("Reversed List: ");
					print_in_reverse_order(head);
					printf("\n");
	    			break;

	    	case 10: head=removedup(head);
	    			 break; 

	    	case 11: head=swap_nodes(head);
	    			 break;
	    						
	    	case 12: exit(1);
	    			break;
	    	
	    	default:printf("Please enter a valid input");
	    			break;
		}
	}
	return 0;
}
