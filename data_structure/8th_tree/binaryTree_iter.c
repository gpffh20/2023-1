#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef int element;

typedef struct TreeNode
{
	element data;
	struct TreeNode *left, *right;
}TreeNode;

typedef struct
{
	TreeNode *Stack[N];	// 노드를 넣은 것
	int top;
}StackType;

void init(StackType *S)
{
	S->top = -1;
}

void push(StackType *S, TreeNode *e)
{
	if (S->top < N - 1)
		S->Stack[++S->top] = e;
}

TreeNode *pop(StackType *S)
{
	TreeNode *e = NULL;
	if (S->top >= 0)
		e = S->Stack[S->top--];

	return e;
}

TreeNode *makeNode(element data, TreeNode *left, TreeNode *right)
{
	TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
	node->data = data;
	node->left = left;
	node->right = right;

	return node;
}

void preOrder(TreeNode *root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(TreeNode *root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		printf("[%d] ", root->data);
		inOrder(root->right);
	}
}

void postOrder(TreeNode *root)
{
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		printf("[%d] ", root->data);
	}
}

void iterOrder(TreeNode *root)
{
	StackType S;
	init (&S);

	while (1)
	{
		for (; root != NULL; root = root->left)
			push(&S, root);

		root = pop(&S);
		if (root == NULL)
			break;
		printf("[%d] ", root->data);
		
		root = root->right;
	}
}

int main()
{
	TreeNode *N4 = makeNode(1, NULL, NULL);
	TreeNode *N6 = makeNode(16, NULL, NULL);
	TreeNode *N7 = makeNode(25, NULL, NULL);
	TreeNode *N2 = makeNode(4, N4, NULL);
	TreeNode *N3 = makeNode(20, N6, N7);
	TreeNode *N1 = makeNode(15, N2, N3);

//	printf("Pre : "); preOrder(N1); printf("\n");
//	printf("In : "); inOrder(N1); printf("\n");
//	printf("Post : "); postOrder(N1); printf("\n");

	iterOrder(N1);

	return 0;
}
