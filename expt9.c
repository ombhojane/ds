#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *right;
	struct node *left;
};

struct node *tree = NULL;
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void postorderTraversal(struct node *);
void inorderTraversal(struct node *);

int main()
{
	int option, val;
	struct node *ptr;
	printf("\n*****-MAIN MENU-*****\n");
	printf("\n01. Insert Element");
	printf("\n02. PreOrder Traversal");
	printf("\n03. InOrder Traversal");
	printf("\n04. PostOrder Traversal");
	printf("\n05. Exit");
	do
	{
		printf("\n\nEnter Your Option - ");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			printf("\nEnter the value of new node - ");
			scanf("%d", &val);
			tree = insertElement(tree, val);
			break;
		case 2:
			printf("\nElements of Tree in PreOrder - \n");
			preorderTraversal(tree);
			printf("\n");
			break;
		case 3:
			printf("\nElements of Tree in InOrder - \n");
			inorderTraversal(tree);
			printf("\n");
			break;
		case 4:
			printf("\nElements of Tree in PostOrder - \n");
			postorderTraversal(tree);
			printf("\n");
			break;
		}
	} while (option != 5);
	return 0;
}

struct node *insertElement(struct node *tree, int val)
{
	struct node *ptr, *nodeptr, *parentptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->right = NULL;
	ptr->left = NULL;
	if (tree == NULL)
	{
		tree = ptr;
		tree->right = NULL;
		tree->left = NULL;
	}
	else
	{
		parentptr = NULL;
		nodeptr = tree;
		while (nodeptr != NULL)
		{
			parentptr = nodeptr;
			if (val < nodeptr->data)
				nodeptr = nodeptr->left;
			else
				nodeptr = nodeptr->right;
		}
		if (val < parentptr->data)
			parentptr->left = ptr;
		else
			parentptr->right = ptr;
	}
	return tree;
}

void preorderTraversal(struct node *tree)
{
	if (tree != NULL)
	{
		printf("%d\t", tree->data);
		preorderTraversal(tree->left);
		preorderTraversal(tree->right);
	}
}

void postorderTraversal(struct node *tree)
{
	if (tree != NULL)
	{
		postorderTraversal(tree->left);
		postorderTraversal(tree->right);
		printf("%d\t", tree->data);
	}
}

void inorderTraversal(struct node *tree)
{
	if (tree != NULL)
	{
		inorderTraversal(tree->left);
		printf("%d\t", tree->data);
		inorderTraversal(tree->right);
	}
}
