#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERROR -1
#define MAXSIZE 1000

struct Queue{
	int front, rear;
	int Q[MAXSIZE];
}; 
typedef struct Queue QUEUE;



int initQueue(QUEUE *queue)
{
	queue->front = 0;
	queue->rear = 0;
	
	return OK;
}


int isEmpty(QUEUE *queue)
{
	if (queue->front >= queue->rear )
		return 1;
	else 
		return 0;
}
		
		
int push(QUEUE *queue, int t)
{
	if(queue->rear >= MAXSIZE)
		return ERROR;
		
	t = queue->Q[queue->rear];
	(queue->rear )++;
	
	return OK;
}


	


int pop(QUEUE *queue,int *t)
{
	if(isEmpty(queue)==1)
		return ERROR;
	
	*t=queue->Q [queue->front];
	(queue->front)++;
	
	return OK;	
}


int main()
{	
	int n,T,temp;
	char X;
	QUEUE *queueA, *queueB, *queueC;
	
	queueA = (QUEUE *)malloc(sizeof(QUEUE));
	queueB = (QUEUE *)malloc(sizeof(QUEUE));
	queueC = (QUEUE *)malloc(sizeof(QUEUE));

	initQueue(queueA);
	initQueue(queueB);
	initQueue(queueC);
	
	scanf("%d",&n);
	
	while(n--)
	{
		getchar();
		scanf("%c%d",&X, &T);
		switch(X)
		{
			case'A':
				push(queueA, T);
				
			case'B':
				push(queueB, T);
			
			case'C':
				push(queueC, T);
			
		}
		
	}
	int a;
	while(isEmpty(queueA) != 1)
	{
	
		pop(queueA,&temp);
		a = a+temp;	 
	}
	printf("%d\n", a);
	
	int b;
	while(isEmpty(queueB) != 1)
	{

		pop(queueB,&temp);
		b = b +temp;	 
	}
	printf("%d\n",b);
	
	int c;
	while(isEmpty(queueC) != 1)
	{
		pop(queueC,&temp);
		c = c+temp;	 
	}
	printf("%d\n",c);
	
	

	return 0;
}

