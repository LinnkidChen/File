#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLEN 1000

struct BinaryTreeNode{
	char data;
	struct BinaryTreeNode *lson;
	struct BinaryTreeNode *rson;
	
	
}; 
typedef struct BinaryTreeNode BTNode;


BTNode *createTree(char st[],int &pos)
{
	BTNode *node;
	char c;
	c = st[pos++];
	if(c=='0')
		node=NULL;	
	else
	{
		node=(BTNode*)malloc(sizeof(BTNode));
		node->data = c;
		node->lson = createTree(st, pos);
		node->rson = createTree(st, pos);	
	}
	return node;
}

void freeTree(BTNode *node)
{
	if(node != NULL)
	{
		freeTree(node->lson);
		freeTree(node->rson);
		free(node);
	}
}

void Pre(BTNode *node)
{
	if(node != NULL)
	{
		printf("%c",node->data);
		Pre(node->lson);
		freeTree(node->lson);
		Pre(node->rson);
		freeTree(node->rson);
	}
}

void In(BTNode *node)
{
	if(node != NULL)
	{
		In(node->lson);
		freeTree(node->lson);
		printf("%c",node->data);
		In(node->rson);
		freeTree(node->rson);
	}
}

void Pos(BTNode *node)
{
	if(node != NULL)
	{
		Pos(node->lson);
		freeTree(node->lson);
		Pos(node->rson);
		freeTree(node->rson);
		printf("%c",node->data);
	}
}

int main()
{
	int T, pos;
	BTNode *tree;
	
	scanf("%d",&T);
	while(T--)
	{
		char st[MAXLEN];
		scanf("%s",st);
		
		pos = 0;
		tree = createTree(st, pos);
		Pre(tree);
		printf("\n");
		
		In(tree);
		printf("\n");
		
		Pos(tree);
		printf("\n");
		
		freeTree(tree);
		
	}
	return 0;
}



