/*
	Authors:
	-Lampros Grammatikopoulos
	 AM:2022201800038
	-Kwnstantinos Kolotouros
	 AM:2022201800090
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct listpointer
{
	int x;
	struct listpointer *next;
}list;
list *array,*head=NULL,*tmp=NULL,*new=NULL,*tmp2=NULL,*tmp3=NULL;
int N=0,n=0,i=0,flag=0,n1=0;
list *insertstart(list *h, int n);
list* copy(list *head);
void push(list h);
list *pop();
list* intcomp(int n,int i);
list *deletestart(list *h);
int main(void)
{
	//pairnoume to megethos tou pinaka-stoiva
	do
	{
		printf("Dwste akeraio thetiko airthmo: ");
		scanf("%d",&n);
	}while(n<=0);
	//dhmiourgoume ton pinaka pou antiproswpeuei thn stoiva
	array=(list*)malloc(sizeof(list)*(pow(2,n-1)));
	if(array==NULL)
	{
		printf("Out of memory.\n");
		return 0;
	}
	//arxikopoioume to prwto stoixeio
	head=(list*)malloc(sizeof(list));
	head->x=n;
	head->next=NULL;
	push(*head);
	n1=n;
	while(N!=0)
	{
		//vgazoume to athroisma apo thn stoiva
		head=pop();
		//antigrafoume thn lista ston tmp an to prwto psifio ths den einai ena
		if(head->x!=1)
		{
			tmp=copy(head);
		}
		//dhkths pou xrhsimopoioume gia thn ektupwsh
		tmp2=head;
		//allazoume to orisma ths sunarthshs
		n=head->x;
		//diatrexoume thn lista kai thn ektupwnoume kathe fora pou trexei h while
		while(tmp2!=NULL)
		{
			if(tmp2->next==NULL)
			{
				printf("%d",tmp2->x);
			}
			else
			{
				printf("%d+",tmp2->x);
			}
			tmp2=tmp2->next;
		}
		printf("\n");
		//ftiaxnoume ta athroismata
		for(i=1;i<n;i++)
		{
			head=intcomp(n,i);
			push(*head);
		}
	}
	//kanoume free
	free(head);
	free(new);
	return 0;
}



void push(list h)
{
	array[N++]=h;
}



list *pop()
{
	return &array[--N];
}



list *insertstart(list *h, int n)
{
	new=(list*)malloc(sizeof(list));
	new->x=n;
	new->next=h;
	return new;
}



list *copy(list *h)
{
	list *current =head;
	list *newList=NULL;
	list *tail=NULL;
	while(current!=NULL)
	{
		if(newList==NULL)
		{
			newList=(list*)malloc(sizeof(list));
			newList->x=current->x;
			newList->next=NULL;
			tail=newList;
		}
		else
		{
			tail->next=(list*)malloc(sizeof(list));
			tail=tail->next;
			tail->x=current->x;
			tail->next=NULL;
		}
		current=current->next;
	}
	return newList;
}



list *deletestart(list *h)
{
	list *k;
	if(h==NULL)
	{
		return NULL;
	}
	else if(h->next==NULL)
	{
		free(h);
		return NULL;
	}
	else
	{
		k=h;
		h=k->next;
		return h;
	}
}



list* intcomp(int n,int i)
{
	if(n!=1 && n!=n1)
	{
		tmp3=deletestart(tmp);
		tmp3=insertstart(tmp3,n-i);
		tmp3=insertstart(tmp3,n-(n-i));
		return tmp3;
	}
	else
	{
		head=insertstart(head,n-i);
		head->next=NULL;
		head=insertstart(head,n-(n-i));
		return head;
	}
}





