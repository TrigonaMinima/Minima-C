#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	struct node *right;
	int data;
}*root=NULL,*temp,*ptr;

int main()
{
	int ch,val,f=1;
	while(f)
	{
		printf("\nEnter your choice:\n1. Insertion \n2. Search\n3. Deletion\n4. Display\n5. Exit\n ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter value to be inserted :");
			scanf("%d",&val);
			insert(val);
			break;
			case 2:
			printf("Enter value to be searched :");
			scanf("%d",&val);
			if(search(val))
			{
				printf("Found\n");
			}
			else
				printf("Not present!!");
			break;
			case 3:
			printf("Enter value to be deleted :");
			scanf("%d",&val);
			if(del(root,val))
			{
				printf("\n %d is deleted! ",val);
			}
			break;
			case 4:
			printf("Tree:\n");
			display(root);
			break;
			case 5:
			f=0;
			break;
			default:
			printf("Wrong choice");
			break;
		}
	}
	return 0;
}
int del(struct node* temp,int val)
{
	int flag=0,cas=0;
	struct node *parent,*ptr1,*ptr;
	if(root==NULL)
	{
		printf("Empty tree!!");
		return 0;
	}
	if(root->data==val && ((root->left==NULL)&&(root->right==NULL)))
	{
		root=NULL;
	}
	ptr = (struct node*)malloc(sizeof(struct node*));
	ptr=temp;
	while(ptr!=NULL && flag==0)
	{
		if(val < ptr->data)
		{
			parent=ptr;
			ptr=ptr->left;
		}
		else if(val > ptr->data)
		{
			parent=ptr;
			ptr=ptr->right;
		}
		else if(ptr->data==val)
		{
			flag=1;
		}
	}


	if(flag==0)
	{
		printf("No such value exists:No deletion!");
		return 0;
	}

	//decide the case of deletion
	if(ptr->left==NULL && ptr->right==NULL)
		cas=1;
	else
	{
		if(ptr->left!=NULL && ptr->right!=NULL)
			cas=3;
		else
			cas=2;
	}
	//deletion: Case 1
	if(cas==1)
	{
		if(parent->left==ptr)
			parent->left=NULL;
		else
			parent->right=NULL;
		free(ptr);
	}

	//deletion: case 2
	if(cas==2)
	{
		if(parent->left==ptr)
		{
			if(ptr->left==NULL)
				parent->left=ptr->right;
			else
				parent->left=ptr->left;
		}
		else
		{
			if(parent->right==ptr)
			{
				if(ptr->left==NULL)
					parent->right=ptr->right;
				else
					parent->right=ptr->left;
			}
		}
	}
	if(cas==3)
	{
		ptr1=ptr->right;
		if(ptr1 != NULL)
		{
			while(ptr1->left!=NULL)
			{
				ptr1=ptr1->left;
			}
		}
		val=ptr1->data;
		del(root,val);
		ptr->data=val;
	}
	return 1;
}
int display(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Empty tree!!\n");
	}
	else
	{
		if(ptr->left!=NULL)
			display(ptr->left);
		printf("%d,",ptr->data);
		if(ptr->right!=NULL)
			display(ptr->right);
	}
}
int search(int val)
{
	temp = root;
	while(temp->left != NULL || temp->right != NULL)
	{
		if (val == temp->data )
		{
			return 1;
		}
		else if(val < temp->data && temp->left!=NULL)
			temp=temp->left;
		else if(val > temp->data && temp->right != NULL)
			temp=temp->right;
	}
	if (val == temp->data)
		return 1;
	return 0;
}
int insert(int val)
{
	ptr = (struct node*)malloc(sizeof(struct node*));
	ptr->data=val;
	ptr->left=NULL;
	ptr->right=NULL;
	if(root==NULL)
		root=ptr;
	else
	{
		temp=root;
		while(val < temp->data || val > temp->data)
		{
			if(val > temp->data && temp->right!=NULL)
				temp=temp->right;
			else if(val < temp->data && temp->left!=NULL)
				temp=temp->left;
			else
				break;
		}

		if(val < temp->data)
		{
			temp->left=ptr;
		}
		else
		{
			temp->right=ptr;
		}
	}
	return 0;
}
