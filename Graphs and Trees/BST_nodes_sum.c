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


int sum(struct node *ptr)
{
	int s=0;
	if(root == NULL)
	{
		printf("\nEmpty Tree\n");
		return 0;
	}
	else if(ptr->left == NULL && ptr->right == NULL)
		return ptr->data;
	else
	{
		if(ptr->left != NULL)
			s += sum(ptr->left);
		if(ptr->right != NULL)
			s += sum(ptr->right);
	}
	return s;
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


int main()
{
	insert();
	display(root);
	printf("The sum of nodes = %d\n", sum(root));

	return 0;
}
