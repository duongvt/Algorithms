#include<bits/stdc++.h>
using namespace std;

vector<int> v,s;

int findmin(struct node* root);

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* getnode(int data)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	
	return newnode;
}

struct node* insert_recursive(struct node* root,int data)
{
	struct node* newnode=getnode(data);
	if(root==NULL)
	{
		root=newnode;
	}		
	else if(data<=root->data) root->left=insert_recursive(root->left,data);
	else root->right=insert_recursive(root->right,data);
	
	return root;
}

struct node* insert_iterative(struct node* root,int data)
{
	struct node* newnode=getnode(data);
	struct node* temp=root;

	if(root=NULL) root=newnode;
	else
	{
		while(temp->left==NULL||temp->right==NULL)
		{
			if(data<temp->data) temp=temp->left;
			else temp=temp->right;
		}

		if(data<temp->data) temp->left=newnode;
		else temp->right=newnode;
	}
	return root;
}


struct node* Delete(struct node* root,int data)
{
	if(root==NULL) return root;
	else if(data<root->data) root->left=Delete(root->left,data);
	else if(data>root->data) root->right=Delete(root->right,data);
	else
	{
		if(root->left==NULL&&root->right==NULL)
		{
			free(root);
			root=NULL;
		}
		else if(root->left==NULL)
		{
			struct node* temp=root;
			root=root->right;
			free(temp);
		}
		else if(root->right==NULL)
		{
			struct node* temp=root;
			root=root->left;
			free(temp);
		}
		else
		{
			int min=findmin(root->right);
			root->data=min;
			printf("%d \n",min);
			root->right=Delete(root->right,min);
		}
	}
	return root;
}


bool search(struct node* root,int data)
{
	if(root==NULL) return false;
	else if(root->data==data) return true;
	else if(data<=root->data) return search(root->left,data);
	else return search(root->right,data);
}

void preorder(struct node* root)
{
	if(root==NULL) return;
	
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void preorder_iterative(struct node* root)
{
	if(root==NULL) return;
	stack<struct node*> s;
	s.push(root);

	while(!s.empty())
	{
		root=s.top();
		printf("%d ",root->data);
		s.pop();
		if(root->right!=NULL) s.push(root->right);
		if(root->left!=NULL) s.push(root->left);
	}
}

void inorder(struct node* root)
{
	if(root==NULL) return;
	
	inorder(root->left);
//	printf("%d ",root->data);
	s.push_back(root->data);
	inorder(root->right);
}

void inorder_iterative(struct node* root)
{
	if(root==NULL) return;
	stack<struct node*> s;

	while(true)
	{
		if(root!=NULL)
		{
			s.push(root);
			root=root->left;
		}
		if(root==NULL)
		{
			if(s.empty()) break;
			root=s.top();
			printf("%d ",root->data);
			s.pop();
			root=root->right;
		}
	}
}

void postorder(struct node* root)
{
	if(root==NULL) return;
	
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

void postorder_iterative(struct node* root)
{
	if(root==NULL) return;

	stack<struct node*> s1,s2;
	s1.push(root);

	while(!s1.empty())
	{
		root=s1.top();
		s2.push(root);
		s1.pop();

		if(root->left!=NULL) s1.push(root->left);
		if(root->right!=NULL) s1.push(root->right);
	}

	while(!s2.empty())
	{
		root=s2.top();
		printf("%d ",root->data);
		s2.pop();
	}
}

void postorder_stack(struct node* root)
{
	if(root==NULL) return;
	stack<struct node*> s;
	struct node* current=root;

	while(!s.empty()||current!=NULL)
	{
		if(current!=NULL)
		{
			s.push(current);
			current=current->left;
		}
		else
		{
			struct node* temp=s.top()->right;
			if(temp!=NULL) current=temp;
			else
			{
				temp=s.top();
				printf("%d ",temp->data);
				s.pop();
				while(!s.empty()&&temp==s.top()->right)
				{
					temp=s.top();
					printf("%d ",temp->data);
					s.pop();
				}
			} 
		}
	}
}

int findheight(struct node* root)
{
	if(root==NULL) return -1;
	int leftheight=findheight(root->left);
	int rightheight=findheight(root->right);
	
	return max(leftheight,rightheight)+1;
}

int findmin(struct node* root)
{
	struct node* temp=root;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp->data;
}

int findmax(struct node* root)
{
	struct node* temp=root;
	while(temp->right!=NULL)
	{
		temp=temp->right;
	}
	return temp->data;
}

int lca(struct node* root,int n1,int n2)
{
	while(true)
	{
		if(root->data<n1&&root->data<n2) root=root->right;
		else if(root->data>n1&&root->data>n2) root=root->left;
		else return root->data;
	}
}

int find(int in[],int start,int end,int data)
{
	int i;
	for(i=start;i<=end;i++)
	{
		if(data==in[i]) return i;
	}
}

struct node* build_tree(int pre[],int in[],int start,int end)
{
	if(start>end) return NULL;
	int index=0;

	struct node* newnode=getnode(pre[index++]);
	if(start==end) return newnode;

	int newindex=find(in,start,end,newnode->data);
	newnode->left=build_tree(pre,in,start,newindex-1);
	newnode->right=build_tree(pre,in,newindex+1,end);
	return newnode;
}


struct node* findElement(struct node* root,int data)
{
	if(root==NULL) return NULL;

	while(root!=NULL)
	{
		if(data<root->data) root=root->left;
		else if(data>root->data) root=root->right;
		else break;
	}
	return root;
}

struct node* min(struct node* root)
{
	struct node* temp=root;

	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}


struct node* inorder_successor(struct node* root,int data)
{
	struct node* current=findElement(root,data);
	struct node* temp;

	if(current==NULL) return NULL;

	if(current->right!=NULL) 
	{
		temp=min(current->right);
		return temp;
	}
	else
	{
		struct node *successor=NULL,*ancestor=root;
		while(ancestor!=current)
		{
			if(current->data<ancestor->data)
			{
				successor=ancestor;
				ancestor=ancestor->left;
			}
			else
			{
				ancestor=ancestor->right;
			}
		}
		return successor;
	}
}


int validBST(struct node* root,int min,int max)
{
	if(root==NULL) return 1;
	if(root->data<=min||root->data>=max) return 0;

	return validBST(root->left,min,root->data)
	&& validBST(root->right,root->data,max);
}


int roottoleaf(struct node* root,int data)
{
	if(root==NULL) return 0;
	if(root->left==NULL&&root->right==NULL)
	{
		if(root->data==data) return 1;
		else return 0;
	}

	if(roottoleaf(root->left,data-root->data)) return 1;
	if(roottoleaf(root->right,data-root->data)) return 1;

	return 0;
}

struct node* inorder_predecessor(struct node* root,struct node* current)
{
	if(root==NULL) return NULL;
	struct node* temp=root;

	while(temp->right!=NULL&&temp->right!=current)
	{
		temp=temp->right;
	}
	return temp;
}


void morris_inorder(struct node* root)
{
	struct node* current=root;
	struct node* predecessor;

	while(current!=NULL)
	{
		if(current->left==NULL)
		{
			printf("%d ",current->data);
			current=current->right;
		}
		else
		{
			 predecessor=inorder_predecessor(current->left,current);

			if(predecessor->right==NULL)
			{
				predecessor->right=current;
				current=current->left;
			}
			else
			{	
				predecessor->right=NULL;
				printf("%d ",current->data);
				current=current->right;
			}
		}
	}
}


void level_order(struct node* root)
{
	if (root==NULL) return;
	queue<struct node*> q;

	q.push(root);

	while(!q.empty())
	{
		root=q.front();
		printf("%d ",root->data);
		q.pop();

		if(root->left!=NULL) q.push(root->left);
		if(root->right!=NULL) q.push(root->right);
	}
}



void reverse_level_order(struct node* root)
{
	if(root==NULL) return;

	stack<struct node*> s;
	queue<struct node*> q;

	q.push(root);
	while(!q.empty())
	{
		root=q.front();
		q.pop();
		s.push(root);

		if(root->right!=NULL) q.push(root->right);
		if(root->left!=NULL) q.push(root->left);
	}

	while(!s.empty())
	{
		printf("%d ",s.top()->data);
		s.pop();
	}
}


void level_order_level_by_level(struct node* root)
{
	if(root==NULL) return;
	queue<struct node*> q;

	q.push(root);
	q.push(NULL);
	
	while(!q.empty())
	{
		root=q.front();
		printf("%d ",root->data);
		q.pop();
		if(root==NULL)
		{
			if(q.empty()) break;
			else printf("\n");
		}

		if(root->left!=NULL) q.push(root->left);
		if(root->right!=NULL) q.push(root->right);
	}
}

void spiral_level_order(struct node* root)
{
	if(root==NULL) return;
	stack<struct node*> s1,s2;

	s1.push(root);

	while(!s1.empty()||!s2.empty())
	{
			while(!s1.empty())
			{
				root=s1.top();
				printf("%d ",root->data);
				s1.pop();

				if(root->left!=NULL) s2.push(root->left);
				if(root->right!=NULL) s2.push(root->right);
			}
			while(!s2.empty())
			{
				root=s2.top();
				printf("%d ",root->data);
				s2.pop();

				if(root->right!=NULL) s1.push(root->right);
				if(root->left!=NULL) s1.push(root->left);
			}
	}
}

struct node* lca2(struct node* root,int n1,int n2)
{
	if(root==NULL) return NULL;
	if(root->data==n1||root->data==n2) return root;

	struct node* left=lca2(root->left,n1,n2);
	struct node* right=lca2(root->right,n1,n2);

	if(left!=NULL&&right!=NULL) return root;
	if(left==NULL&&right==NULL) return NULL;

	return left!=NULL?left:right;
}


void print_result(int res[],int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("%d ",res[i]);
	}
	printf("\n");
}

void print_paths(struct node* root,int res[],int len)
{
	if(root==NULL) return;

	res[len]=root->data;
	len++;

	if(root->left==NULL&&root->right==NULL) 
	{
		print_result(res,len);
	}

	print_paths(root->left,res,len);
	print_paths(root->right,res,len);
}

int getsize(struct node* root)
{
	if(root==NULL) return 0;

	int leftsize=getsize(root->left);
	int rightsize=getsize(root->right);

	return leftsize+rightsize+1;
}


int main()
{
	struct node* root=NULL;
	struct node* root2=NULL;
	int w;
	struct node* temp;
	int pre[]={40,35,28,19,37,86,78,90,88};
	int in[]={19,28,35,37,40,78,86,88,90};
	int len=9,min=-999,max=999;
	int n,x,y,z,res[10000],sum;
	
	while(1)
	{
		printf("1.Insert using recursive method\n");
		printf("2.Search an element\n");
		printf("3.Delete an element\n");
		printf("4.Preorder Traversal\n");
		printf("5.Inorder Travsersal\n");
		printf("6.Postorder Traversal\n"); 
		printf("7.Minimum element\n");
		printf("8.Maximum element\n");
		printf("9.Height of tree\n");
		printf("10.Insert using iterative method\n");
		printf("11.Preorder using iterative method\n");
		printf("12.Inorder using iterative method\n");
		printf("13.Postorder using iterative method\n");
		printf("14.Postorder using 1 stack\n");
		printf("15.Lowest common ancestor of BST\n");
		printf("16.Construct tree from preorder and inorder\n");
		printf("17.Find Inorder Successor\n");
		printf("18.Check whether tree is BST or not\n");
		printf("19.Root to leaf path sum\n");
		printf("20.Morris Inorder Traversal\n");
		printf("21.Level Order Traversal\n");
		printf("22.Reverse level order traversal\n");
		printf("23.Level order traversal level by level\n");
		printf("24.Spiral level order traversal\n");
		printf("25.Lowest common ancestor of binary tree\n");
		printf("26.Print all root to leaf paths\n");
		printf("27.Find kth smallest element in BST.\n");
		printf("28.Find size of tree\n");
		printf("29.Exit\n");
		
		scanf("%d",&n);
		
		switch(n)
		{
			case 1: printf("Enter an element to insert\n");
					scanf("%d",&x);
					root=insert_recursive(root,x);
					printf("%d inserted\n",x);
					break;
					
			case 2: printf("Enter an element to search\n");
					scanf("%d",&x);
					y=search(root,x);
					printf("%d\n",y);
					if(y==1) printf("Element found\n");
					else printf("Element not found\n");
					break;
					
			case 3: printf("Enter an element to delete\n");
					scanf("%d",&x);
					root=Delete(root,x);
					printf("%d deleted\n",x);
					break;
					
			case 4: preorder(root);
					printf("\n");
					break;
					
			case 5: inorder(root);
					printf("\n");
					break;
					
			case 6: postorder(root);
					printf("\n");
					break;
					
			case 7: y=findmin(root);
					printf("Minimum element: %d\n",y);
					break;
					
			case 8: y=findmax(root);
					printf("Maximum element: %d\n",y);
					break;

			case 9: y=findheight(root);
					printf("Height of tree: %d\n",y);
					break;

			case 10: printf("Enter an element to insert\n");
					scanf("%d",&x);
					root=insert_recursive(root,x);
					printf("%d inserted\n",x);
					break;

			case 11: preorder_iterative(root);
					 printf("\n");
					 break;

			case 12: inorder_iterative(root);
			 		 printf("\n");
					 break;

			case 13: postorder_iterative(root);
					 printf("\n");
					 break;

			case 14: postorder_stack(root);
			         printf("\n");
					 break;

			case 15: printf("Enter the values of 2 nodes\n");
					 scanf("%d%d",&x,&y);
					 z=lca(root,x,y);
					 printf("LCA: %d\n",z);
					 break;

			case 16: root=build_tree(pre,in,0,len-1);
					 printf("Tree constructed\n");
					 break;

			case 17: printf("Enter the element\n");
					 scanf("%d",&x);
					 temp=inorder_successor(root,x);
					 printf("Inorder successor: %d\n",temp->data);
					 break;

			case 18: root2=getnode(2);
					 root2->left=getnode(1);
					 root2->right=getnode(3);
					 preorder(root2);
					 w=validBST(root2,min,max);
					 if(w==1) printf("Valid BST\n");
					 else printf("Not a BST\n");
					 break;

	        case 19: printf("Enter the sum to find\n");
	        		 scanf("%d",&x);
	        		 w=roottoleaf(root,x);
	        		 if(w==1) printf("Path found\n");
					 else printf("Path not found\n");
					 break;

			case 20: morris_inorder(root);
					 printf("\n");
					 break;

			case 21: level_order(root);
					 printf("\n");
					 break;

			case 22: reverse_level_order(root);
					 printf("\n");
					 break;

			case 23: level_order_level_by_level(root);
					 printf("\n");
					 break;

			case 24: spiral_level_order(root);
				     printf("\n");
				     break;

			case 25: printf("Enter 2 values\n");
				     cin>>x>>y;
				     temp=lca2(root,x,y);
				     printf("LCA: %d\n",temp->data);
				     break;

			case 26: print_paths(root,res,0);
					 break;


			case 27: printf("Enter value of k\n");
					 scanf("%d",&x);
					 inorder(root);
					 printf("%d\n",s[x-1]);
					 break;

			case 28: x=getsize(root);
					 printf("%d\n",x);
					 break;

			case 29: exit(1);
					 break;
					
			default:printf("Please enter a valid input\n");
					break;
		}
	}
	return 0;
}
