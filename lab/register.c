#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void QUEUEinit(int maxN);
int QUEUEget();
int QUEUEempty();
void QUEUEput(int item);
int N,head,tail,a,*queue,p,i,j,x,bit;
int main(void)
{
	printf("Give the number of bits\n");
	scanf("%d",&x);
	QUEUEinit(x);
	a=QUEUEempty();
	if(a!=0)
	{
		for(i=0;i<x;i++)
		{
			scanf("%d",&bit);
			QUEUEput(bit);
		}
	}
	//////////////////////////////
	for(i=0;i<x;i++)
	{
		p=QUEUEget();
		printf("%d",p);
		QUEUEput(p);
	}
	printf("\n");
	for(j=0;j<pow(2,x)-1;j++)
	{
		p=QUEUEget();
		p=p^(queue[head%N]);
		printf("The bit is: %d\n",p);
		QUEUEput(p);
		///////////////////////////////
		for(i=0;i<x;i++)
		{
			p=QUEUEget();
			printf("%d",p);
			QUEUEput(p);
		}
		printf("\n");
	}
	return 0;
}

void QUEUEinit(int maxN)
{ 
	queue = (int *)malloc((maxN+1)*sizeof(int)); 
	N = maxN+1;
	head = N;
	tail = 0;
}

int QUEUEempty()
{
	return head % N == tail;
}
int QUEUEget()
{
	head = head % N;
	return queue[head++];
}

void QUEUEput(int item)
{
	queue[tail++] = item;
	tail = tail % N;
}
	

