#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLEN 1000

void get_next(char t[], int next[], int n)
{
	int j,k;
	j=0;
	k=-1;
	next[0]=0;
	while(j<n)
	{
		if(k == -1 || t[j]==t[k])
		{
			j++;
			k++;
			next[j]=k;	
		}
		else k=next[k];
		
	}
} 

int count_KMP(char s[], char t[], int next[])
{
	int i = 0;
	int j = 0, m, n;
	int counter = 0;
	m = strlen(s);
	n = strlen(t);
	while(i<m && j<n)	
	{	printf("%c %c\n",s[i],t[j]);
		if(j == -1 || s[i]==t[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
		
		if(j>=n-1)
		{
			
			j=0;
			counter++;
			i++;

			printf("%d %d\n",i,counter);
		}	
	}
	return counter;
}

int main()
{
	int next[MAXLEN];
	char s[MAXLEN];
	char t[MAXLEN];
	
	scanf("%s",s);
	scanf("%s",t);
	get_next(t,next,strlen(t)) ;
	for(int i=0;i<strlen(t);i++){
		printf("%d ",next[i]);
	}
	printf("\n");
	printf("%d\n", count_KMP(s,t,next));
	
	return 0;
}
