/*
*The diameter of a tree T is the largest of the following quantities:
* the diameter of T's left subtree
* the diameter of T's right subtree
* the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)
*/

# include <stdio.h>
# include <stdlib.h>

// A BST node
struct node
{
	int data;
	struct node *left;
	struct node *right;
} *root=NULL, *temp;

// Gives inorder traversal of BST
int display(struct node *ptr)
{
	if(root == NULL)
		printf("Empty tree!!\n");
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

// Inserts data in the nodes
int insertion()
{
	struct node *new;
	int ele;
	new = (struct node *) malloc(sizeof(struct node *));

	printf("Enter the element: ");
	scanf("%d", &ele);
	fflush(stdin);
	new->data = ele;
	new->left = NULL;
	new->right = NULL;

	if(root == NULL)
		root  = new;
	else
	{
		temp = root;
		while(1)
		{
			if((temp->data) >= ele && (temp->left) != NULL)
				temp = temp->left;
			else if((temp->data) < ele && (temp->right) != NULL)
				temp = temp->right;
			else
				break;
		}
		if(temp->data < ele)
			temp->right = new;
		else
			temp->left = new;
	}
	return 0;
}


int insert()
{
	int choice=0;
	while(1)
	{
		insertion();
		display(root);
		printf("\nWan't to enter more? (1/0)");
		scanf("%d", &choice);
		if(choice == 0)
			break;
	}
	return 0;
}


int max(int a, int b)
{
	return (a >= b)? a: b;
}

// Finds the height of the tree
int height(struct node* node)
{
	if(node == NULL)
		return 0;

	return (1 + max(height(node->left), height(node->right)));
}

// Finds the diameter of the tree
int diameter(struct node *tree)
{
	if (tree == 0)
		return 0;

	/* get the height of left and right sub-trees */
	int lheight = height(tree->left);
	int rheight = height(tree->right);

	/* get the diameter of left and right sub-trees */
	int ldiameter = diameter(tree->left);
	int rdiameter = diameter(tree->right);

	/* Return max of following three
	1) Diameter of left subtree
	2) Diameter of right subtree
	3) Height of left subtree + height of right subtree + 1 */
	return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}


int main()
{
	insert();
	printf("\nThe inorder traversal of tree is: \n");
	display(root);
	printf("\nThe Diameter of the entered BST is: %d\n", diameter(root));

	return 0;
}