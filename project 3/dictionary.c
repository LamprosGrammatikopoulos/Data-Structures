/*
	Authors:
	Grammatikopoulos Lampros
	A.M.:2022201800038
	Kolotouros Kwnstantinos
	A.M.:2022201800090
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxwords 183719
#define BYTE 4
#define maxwordsize 100
char **hashtable=NULL,str[100],str[100],word[100],ch,sortedword[100];
int line=-5,POSITION=0,number=0;
typedef struct list
{
	char *sortedstr;
	struct list *next;
}list;
list **hashtableV2=NULL;
unsigned int strtohash(char *str,int number);
void dictionarysorter(int ui,int number);
void dictionaryV2(int ui,int number);
void dictionarysearch(int ui2,int number);
int strCMP(int x);
void printlist(list *head);
void procedure(int ui2);
char *stringsorter(char *string);
list *insertend(list *h,char *c);
void dictionarysearchforanagrams(int ui2,int number,char *sortedword);
void freelist(list *head);
int search();
void anagramspositions(char *s);
void printanagramspositions(list *head,char*s);
int main(void)
{
	FILE *fp;
	int i,j;
	unsigned int ui=0;
	int DONE=0;
	
	
	////////*Prwto erwthma*////////
	//Pairnoume to arithmo leksewn tou pinaka apo ton xrhsth
	do
	{
		printf("Give numbers of words.\n");
		scanf("%d",&number);
	}while(number<=0 || number>maxwords);
	//Ftiaxnoume ton pinaka
	hashtable=(char**)malloc(number*sizeof(char*));
	if(hashtable==NULL)
	{
		printf("Error.\n");
		return 0;
	}
	//Gemizoume ton pinaka me NULL
	for(i=0;i<number;i++)
	{
		hashtable[i]=NULL;
	}
	//Anoigoume to arxeio me tis lekseis
	fp=fopen("dictionary.txt","r");
	if(fp==NULL)
	{
		printf("Could not open file.\n");
		return 0;
	}
	//Diavazoume thn leksh apo to arxeio, thn pairname sthn strtohash kai xrhsimopoioume ton arithmo pou paragei h strtohash gia na valoume se ekeinh thn thesh tou pinaka thn leksh
	for(i=0;i<number;i++)
	{
		fscanf(fp,"%s",str);
		ui=strtohash(str,number);
		dictionarysorter(ui,number);
	}
	//Ektupwnoume ton pinaka me tis lekseis
	printf("\n");
	for(i=0;i<number;i++)
	{
		printf("(%s)\n",hashtable[i]);
	}
	//pernoume to /n apo to number pou edwse o xrhsths
	ch=getchar();
	printf("\n");
	//Pairnoume apo ton xrhsth thn leksh pou thelei na vrei ston pinaka leksewn
	printf("Please give a word to search in the dictionary.\n");
	i=0;
	while((ch=getchar())!='\n' && ch!=EOF)
	{
		word[i]=ch;	
		i++;
	}
	//Vazoume thn leksh pou edwse o xrhsths sthn sunarthsh strtohash gia na mas paraksei enan arithmo
	int ui2=strtohash(word,number);
	//Xrhsimopoioume ton arithmo pou proekupse apo thn sunarthsh strtohash gia na pame se ekeinh thn thesh ston pinaka kai na doume an h leksh uparxei
	dictionarysearch(ui2,number);
	if(line==-5)
	{
		printf("Word was not found.\n");
	}
	else
	{
		printf("Word was found.\n");
		printf("Hash function value:%d.\n",ui2);
		printf("Word was found in position:%d.\n",line);
		////////////////////////////*Deftero erwthma*////////////////////////////////////
		//Pairname thn leksh sthn strtohash kai xrhsimopoioume ton arithmo pou paragei h strtohash gia na valoume se ekeinh thn thesh tou pinaka thn leksh
		strcpy(sortedword,stringsorter(word));
		ui=strtohash(str,number);
		dictionaryV2(ui,number);
		//Diatrexoume ton pinaka
		int x=search();
		if(x==0)
		{
			printf("There are no anagrams.\n");
		}
		else
		{
			printf("Available anagrams:");
			//Vazoume tous anagrammatismous sthn lista
			dictionarysearchforanagrams(ui2,number,sortedword);
			//Ektupwnoume thn lista
			printlist(hashtableV2[POSITION]);
			//Ektupwnoume tis theseis twn anagrammatismwn
			printanagramspositions(hashtableV2[POSITION],sortedword);
		}
	}
	printf("\n");
	//Kanoume free thn mnhmh pou epiasan oi pinakes
	for(i=0;i<number;i++)
	{
		free(hashtable[i]);
	}
	free(hashtable);
	freelist(hashtableV2[POSITION]->next);
	for(i=0;i<number;i++)
	{
		free(hashtableV2[i]);
	}
	free(hashtableV2);
	//Kleinoume to arxeio me tis lekseis
	fclose(fp);
	return 0;
}



//Katakermatimos
unsigned int strtohash(char *str,int number)
{
	unsigned int hash=0;
	while(*str)
	{
		hash=*str+31*hash;
		str++;
	}
	return hash%number;
}



//Vazoume tis lekseis ston prwto pinaka
void dictionarysorter(int ui,int number)
{
	int position=0,j;
	if(hashtable[ui]==NULL)
	{
		hashtable[ui]=(char*)malloc((strlen(str)+1)*sizeof(char));
		if(hashtable[ui]==NULL)
		{
			printf("Error.\n");
		}
		else
		{
			strcpy(hashtable[ui],str);
		}
	}
	else
	{
		position=ui;
		int j=0,fl=0;
		for(j=ui+1;j<number;j++)
		{
			if(hashtable[j]==NULL)
			{
				hashtable[j]=(char*)malloc((strlen(str)+1)*sizeof(char));
				if(hashtable[j]==NULL)
				{
					printf("Error.\n");
				}
				else
				{
					strcpy(hashtable[j],str);
					fl=1;
					break;
				}
			}
		}
		if(fl==0)
		{
			for(j=0;j<position;j++)
			{
				if(hashtable[j]==NULL)
				{
					hashtable[j]=(char*)malloc((strlen(str)+1)*sizeof(char));
					if(hashtable[j]==NULL)
					{
						printf("Error.\n");
					}
					else
					{
						strcpy(hashtable[j],str);
						break;
					}
				}
			}
		}
	}
}



//Kuklikh anazhthsh
void dictionarysearch(int ui2,int number)
{
	int position=0,j=0,fl=0;
	if(strcmp(hashtable[ui2],word)==0)
	{
		line=ui2;
		POSITION=line;
	}
	else
	{
		position=ui2;
		for(j=ui2+1;j<number;j++)
		{
			if(strcmp(hashtable[j],word)==0)
			{
				line=j;
				POSITION=line;
				fl=1;
				break;
			}
			else
			{
				line=-5;
			}
		}
		if(fl==0)
		{
			for(j=0;j<position;j++)
			{
				if(strcmp(hashtable[j],word)==0)
				{
					line=j;
					POSITION=line;
					break;
				}
				else
				{
					line=-5;
				}
			}
		}
	}
}



//Antigrafoume ton prwto pinaka ston deftero
void dictionaryV2(int ui,int number)
{
	int position=0,j,i;
	hashtableV2=(list**)malloc(number*sizeof(list*));
	if(hashtableV2==NULL)
	{
		printf("Error.\n");
	}
	for(i=0;i<number;i++)
	{
		hashtableV2[i]=NULL;
	}
	for(i=0;i<number;i++)
	{
		hashtableV2[i]=(list*)malloc(sizeof(list));
		hashtableV2[i]->sortedstr=(char*)malloc((strlen(str)+1)*sizeof(char));
		if(hashtableV2[i]->sortedstr==NULL)
		{
			printf("Error.\n");
		}
		hashtableV2[i]->next=(list*)malloc(sizeof(list));
		if(hashtableV2[i]->next==NULL)
		{
			printf("Error.\n");
		}
		hashtableV2[i]->next=NULL;
		strcpy(hashtableV2[i]->sortedstr,hashtable[i]);
	}
}



char *stringsorter(char *string)
{
	strcpy(str,string);
	char temp;
	int i,j;
	int n=strlen(string);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(str[i]>str[j])
			{
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
			}
		}
	}
	return str;
}



//Vazoume thn taksinomhmenh leksh ston deftero pinaka kai thn leksh tou xrhsth sthn lista
void dictionarysearchforanagrams(int ui2,int number,char *sortedword)
{
	int position=0,j=0,fl=0;				
	POSITION=line;
	strcpy(hashtableV2[POSITION]->sortedstr,sortedword);
	insertend(hashtableV2[POSITION],word);
	procedure(ui2);
}



list *insertend(list *h,char *c)
{
	list *new,*tmp;
	new=(list*)malloc(sizeof(list));
	new->sortedstr=c;
	new->next=NULL;
	if(h==NULL)
	{
		return new;
	}
	else
	{
		tmp=h;
		while(tmp->next!=NULL)
		{
			tmp=tmp->next;
		}
		tmp->next=new;
		return h;
	}
}



//Psaxnoume lekseis kai tis vazoume sthn lista
void procedure(int ui2)
{
		int fl=0;
		int pos=0,j=0;
		if(POSITION!=ui2)
		{
			if(strcmp(stringsorter(hashtable[ui2]),sortedword)==0)
			{
				insertend(hashtableV2[POSITION],hashtableV2[ui2]->sortedstr);
			}
		}
		for(j=POSITION+1;j<number;j++)
		{
			if(strcmp(sortedword,stringsorter(hashtableV2[j]->sortedstr))==0)
			{
				insertend(hashtableV2[POSITION],hashtableV2[j]->sortedstr);
			}
		}
		for(j=0;j<POSITION;j++)
		{
			if(strcmp(sortedword,stringsorter(hashtableV2[j]->sortedstr))==0)
			{
				insertend(hashtableV2[POSITION],hashtableV2[j]->sortedstr);
			}
		}	
}



void printlist(list *head)
{
	list *tmp=head;
	if(head==NULL)
	{
		printf("The list is empty.\n");
	}
	else
	{
		while(tmp->next!=NULL)
		{
			printf("%s->",tmp->sortedstr);
			tmp=tmp->next;
		}
		printf("%s.\n",tmp->sortedstr);
	}
}



void freelist(list* head)
{
	list* tmp;
	while(head!=NULL)
	{
		tmp=head;
		head=head->next;
		free(tmp);
	}
}



//Psaxnoume an uparxoun anagramatimsoi ston deftero pinaka
int search()
{
	int j=0;
	for(j=POSITION+1;j<number;j++)
	{
		if(strcmp(sortedword,stringsorter(hashtableV2[j]->sortedstr))==0)
		{
			return 1;
		}
	}
	for(j=0;j<POSITION;j++)
	{
		if(strcmp(sortedword,stringsorter(hashtableV2[j]->sortedstr))==0)
		{
			return 1;
		}
	}
	return 0;
}



void anagramspositions(char *s)
{
	int i=0;
	for(i=0;i<number;i++)
	{
		if(strcmp(hashtable[i],s)==0)
		{
			printf("Anagram %s located at %d.\n",s,i);
		}
	}
}



void printanagramspositions(list *head,char*s)
{
	list *tmp=head;
	if(head==NULL)
	{
		printf("The list is empty.\n");
	}
	else
	{
		while(tmp->next!=NULL)
		{
			anagramspositions(tmp->sortedstr);
			tmp=tmp->next;
		}
		anagramspositions(tmp->sortedstr);
	}
}





