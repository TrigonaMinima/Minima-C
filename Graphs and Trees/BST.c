# include <stdio.h>
# include <stdlib.h>

struct node
{
	int data;
	struct node *right;
	struct node *left;
} *root = NULL, *temp;


struct  node *newnode()
{
	struct node *new;
	new = (struct node *) malloc(sizeof(struct node *));

	new->right = NULL;
	new->left = NULL;

	return new;
}


int display(struct node *ptr)
{
	if(root == NULL)
		printf("\nEmpty Tree\n");
	else
	{
		if(ptr->left != NULL)
			display(ptr->left);
		printf("%d, ", ptr->data);
		if(ptr->right != NULL)
			display(ptr->right);
	}
	return 0;
}


int insertion()
{
	struct node *new;
	new = newnode();
	printf("Enter the element: ");
	scanf("%d", &(new->data));

	if(root == NULL)
		root = new;
	else
	{
		temp = root;
		while(1)
		{
			if(temp->data > new->data)
			{
				if(temp->left == NULL)
				{
					temp->left = new;
					return 0;
				}
				temp = temp->left;
			}
			else
			{
				if(temp->right == NULL)
				{
					temp->right = new;
					return 0;
				}
				temp = temp->right;
			}
		}
	}
	return 0;
}


int insert()
{
	int ch=1, ele;
	struct node new;
	while(ch)
	{
		insertion();
		display(root);
		printf("Wan't to enter more? (0/1): ");
		scanf("%d", &ch);
	}
	return 0;
}


int deletion(int ele)
{
	int flag=0;
	struct node *ptr, *ptr1;
	// ptr = (struct node*)malloc(sizeof(struct node*));

	if(root == NULL)
		printf("Empty Tree.\n");
	else if(root->data == ele && ((root->left == NULL) && (root->right == NULL)))
	{
		// free(root);
		root = NULL;
	}
	else
	{
		temp = root;
		ptr = temp;
		while(ptr != NULL)
		{
			if(temp->data > ele)
			{
				ptr = temp;
				temp = temp->left;
			}
			else if(temp->data < ele)
			{
				ptr = temp;
				temp = temp->right;
			}
			else if(temp->data == ele)
			{
				flag = 1;
				break;
			}
			else
			{
				printf("\nElement not found!!\n");
				return 0;
			}
		}
		if(flag == 0)
			printf("Element not found!!\n");
		else
		{
			// Left and Right childs of the element node are null
			if(temp->left == NULL && temp->right == NULL)
			{
				if(ptr->left == temp)
					ptr->left = NULL;
				else
					ptr->right = NULL;
				free(temp);
			}
			else if(temp->left == NULL)
			{
				if(ptr->left == temp)
					ptr->left = temp->right;
				else
					ptr->right = temp->right;
				free(temp);
			}
			else if(temp->right == NULL)
			{
				if(ptr->left == temp)
					ptr->left = temp->left;
				else
					ptr->right = temp->left;
				free(temp);
			}
			else
			{
				ptr1 = ptr->right;
				if(ptr1 != NULL)
				{
					while(ptr1->left != NULL)
						ptr1 = ptr1->left;
				}
				ele = ptr1->data;
				deletion(ele);
				ptr->data = ele;
			}
		}
	}
	return 0;
}


int delete()
{
	int ch=1, ele;
	struct node new;
	while(ch)
	{

		printf("Enter the element: ");
		scanf("%d", &ele);
		deletion(ele);
		display(root);
		printf("Wan't to delete more? (0/1): ");
		scanf("%d", &ch);
	}
	return 0;
}

int main()
{
	insert();
	display(root);
	delete();
	display(root);

	return 0;
}
