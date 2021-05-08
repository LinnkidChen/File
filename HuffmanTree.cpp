#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERROR -1

#define N 1005
#define LEN 15

struct HuffmanNode
{
	char c;
	int weight;
	int parent,l,r;
	int vis;
	char code[LEN];
	
};
typedef struct HuffmanNode Node;
Node tree[2*N];

int selectSmallestOne(Node tree[], int size)
{
	int minWeight = 0x3f3f3f3f, ret = 0;
	for (int i=0;i<size; i++)
	{
		if(tree[i].vis == 0 && tree[i].weight <minWeight)
		{
			ret=i;
			minWeight = tree[i].weight ;
		}
	
		
	}
	tree[ret].vis =1;
	return ret;
}



void createTree(Node tree[], int n, char c[],int weight[])
{
	int m, s1, s2;
	m = 2*n-1;
	
	for(int i=0; i<m; i++)
	{
		tree[i].c = tree[i].l = tree[i].parent = tree[i].r =tree[i].weight = -1 ;
		tree[i].vis =0;	
	}
	
	for(int i = 0; i<n; i++)
	{
		tree[i].c = c[i];
		tree[i].weight = weight[i] ;
	}
	
	for(int i = n; i<m; i++)
	{
		s1 = selectSmallestOne(tree, i);
		s2 = selectSmallestOne(tree, i);
		tree[s1].parent =i;
		tree[s2].parent =i;	
		tree[i].l =s1;
		tree[i].r =s2;
		tree[i].weight = tree[s1].weight + tree[s2].weight ;
		
		
	}
}



void generateCodes(Node tree[],int n)
{
	int f, c;
	for(int i=0; i<n; i++)
	{
		char code[LEN]="";
		c = i;
		f = tree[i].parent ;
		int start = n-1;
		
		while(f != -1)
		{
			if(tree[f].l == c)
			  code[--start] = '0';
			else
			  code[--start] = '1';
			
			c = f;
			f = tree[f].parent;	
		
		}
		strcpy(tree[i].code, code);
		
	}
}

void showCodes(Node tree[], int n)
{
	for (int i = 0; i<n; i++)
		printf("%c %s\n", tree[i].c, tree[i].code );
		
}

void encoding(Node tree[],int n, char src[], char dst[])
{
	dst[0]=0;
	for(int i=0; i< strlen(src); i++)
	{
		for(int j = 0;j<n; j++)
			if(src[i] == tree[j].c )
		{
			strcat(dst, tree[j].code );
			break;
		 }	 
	} 
	 
	
}

int main()
{
	int n;
	char c[N];
	int weight[N];
	
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		getchar();
		scanf("%c",&c[i]);
	}
	for (int i=0; i<n;i++)
		scanf("%d",&weight[i]);
		
	createTree(tree, n, c, weight);
	generateCodes(tree, n);
	showCodes(tree,n);
	
	char src[N], dst[N];
	scanf("%s",src);
	encoding(tree, n, src, dst);
	printf("%s\n", dst);
	
	return 0;
	
}










