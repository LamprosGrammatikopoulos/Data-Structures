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
#include <math.h>
#define BITSIZE 8
#define COUNT 10
#define FYLLA 256
typedef struct node *link;
struct node
{
	int x[BITSIZE];
	link left;
	link right;
};
typedef struct node2 *link2;
struct node2
{
	int *x;	
	link2 left;
	link2 right;
};
int BITSIZEXRHSTH=0,allzI=0;
int i=0,B[FYLLA][BITSIZE],k=0,chartoasciiarray[8],h=0,temporary[8],lol=0,itmp=0,JJ=0,II=0,graytoasciiarray[8];
int graycode[FYLLA][BITSIZE],g=0,counter=0,f=0,d=0,FLAG=0,place=0,**arraybit,*binarystring,**allzeros;
FILE *outputfile;
char enter[BITSIZE+1]={'\0'},enterV2[BITSIZE+1]={'\0'};
link root=NULL,root1=NULL,root2=NULL,t=NULL,tmp=NULL;
link2 t1=NULL,t2=NULL,Tree1Root,Tree2Root;
link new(link l, link r);
link CreateTree(int l, int r);
link2 newV2(link2 l, link2 r);
link2 CreateTreeV2(int l, int r);
void insertLEAF(link t1);
void print2DUtil(link root1, int space);
void print2DUtilV2(link2 root1, int space);
void asciitogray(link root1);
void graytoascii(link root2);
void insertLEAFV2(link t2);
void toASCII(char z);
link copy(link r);
void kladi(link g);
void insertLEAFTree1(link2 t1);
void insertLEAFTree2(link2 t2);
void gcodes(int n);
int bintogray(int bin);
int decimalToBinary(int decimalnum);
void binary(int index,int length);
int concat(int a, int b);
link2 copyV2(link2 r);
int main(void)
{
	FILE *fp,*filetxt;
	int c=0,flag=0,I=0,I2=0,j=0;
	char asciicode[2],ch;
	//Anoigoume to arxeio BinarytoGray.txt
	fp=fopen("BinarytoGray.txt","r");
	if(fp==NULL)
	{
		printf("Could not open file.\n");
		return 0;
	}
	//Diatrexoume to arxeio mexri to telos tou
	while(!feof(fp))
	{
		//Apothhkevoume tous ascii kwdikes 
		for(k=0;k<BITSIZE;k++)
		{
			fscanf(fp,"%c",asciicode);
			if(strcmp(asciicode,"\n")==0)
			{
				flag=1;
				break;
			}
			B[I][k]=atoi(asciicode);
		}
		I++;
		if(flag==1)
		{
			break;
		}
		flag=0;
		fscanf(fp,"%c",asciicode);	//<======== (:)
		//Apothhkevoume tous gray kwdikes
		for(i=0;i<BITSIZE;i++)
		{	
			fscanf(fp,"%c",asciicode);
			graycode[I2][i]=atoi(asciicode);
		}
		I2++;
		fscanf(fp,"%c",asciicode);	//<======== (\n)
		fscanf(fp,"%c",asciicode);	//<======== (\0)
		c=c+1;
	}
	//--------------------------1o erwthma------------------------
	//Dhmiourgoume to prwto dentro
	link T=CreateTree(0,FYLLA-1);
	lol=0;
	//Vazoume periexomena sta fulla tou prwtou dentrou
	insertLEAF(T);
	i=0;
	//print2DUtil(T,0);
	//--------------------------2o erwthma------------------------
	//Anoigoume to arxeio this.txt
	filetxt=fopen("this.txt","r");
	if(filetxt==NULL)
	{
		printf("Could not open file.\n");
		return 0;
	}
	//Anoigoume to arxeio outputfile.txt
	outputfile=fopen("outputfile.txt","w");
	if(outputfile==NULL)
	{
		printf("Could not open file.\n");
		return 0;
	}
	//Diatrexoume to arxeio this.txt mexri to telos tou 
	while(!feof(filetxt))
	{
		//Apothhkevoume tous ascii kwdikes
		printf("\nAscii of character in the file.\n");
		fscanf(filetxt,"%c",asciicode);
		char o=asciicode[0];
		toASCII(o);
		for(i=0;i<BITSIZE;i++)
		{
			printf("%d",chartoasciiarray[i]);
		}
		printf("\n");
		i=0;
		//Metatrepoume tous ascii kwdikes sta fulla tou prwtou dentrou se gray
		printf("The Gray is:\n");
		asciitogray(T);
	}
	//Kleinoume to arxeio
	fclose(filetxt);
	printf("\n=======================================\n");
	//--------------------------3o erwthma------------------------
	//Dhmiourgoume to deutero dentro
	link Q=CreateTree(0,FYLLA-1);
	root=copy(Q);
	g=0;
	//Vazoume periexomena sta fulla tou deuterou dentrou
	insertLEAFV2(Q);
	i=0;
	//print2DUtil(Q,0);
	//Anoigoume to arxeio this.txt gia apokwdikopoihsh
	filetxt=fopen("this.txt","r");
	if(filetxt==NULL)
	{
		printf("Could not open file.\n");
		return 0;
	}
	//Diatrexoume to arxeio this.txt mexri to telos tou
	while(!feof(filetxt))
	{
		//Apothhkevoume tous ascii kwdikes
		printf("\nAscii of character in the file.\n");
		fscanf(filetxt,"%c",asciicode);
		char o=asciicode[0];
		toASCII(o);
		for(i=0;i<BITSIZE;i++)
		{
			printf("%d",chartoasciiarray[i]);
		}
		printf("\n");
		i=0;
		//Metatrepoume tous ascii kwdikes sta fulla tou prwtou dentrou se gray
		printf("The Gray is:\n");
		asciitogray(T);
		i=0;
		//Metatrepoume tous gray kwdikes sta fulla tou deuterou dentrou se ascii
		printf("The Ascii from gray is:\n");
		graytoascii(Q);	
	}
	//Kleinoume ta arxeia
	fclose(filetxt);
	fclose(outputfile);
	i=0;
	printf("\n");
	fclose(fp);
	//--------------------------4o erwthma------------------------
	//Anoigoume to arxeio outputfile.txt
	outputfile=fopen("outputfile.txt","r");
	if(outputfile==NULL)
	{
		printf("Could not open file.\n");
		return 0;
	}
	printf("\nDecoded ascii from coded file using gray tree:\n");
	int s=0,akeraios;
	char lex[2];
	//Diatrexoume to arxeio outputfile.txt mexri to telos tou
	while(!feof(outputfile))
	{
		//Apothhkevoume tous gray kwdikes
		for(s=0;s<BITSIZE;s++)
		{
			fscanf(outputfile,"%c",lex);
			akeraios=atoi(lex);
			graytoasciiarray[s]=akeraios;
			i=0;
		}
		//Metatrepoume tous gray kwdikes se ascii
		graytoascii(Q);
	}
	//Kleinoume to arxeio
	fclose(outputfile);
	//--------------------------5o erwthma------------------------
	//Diavazoume ton arithmo twn bit gia thn dhmiourgia tou neou gray kwdika
	do
	{
		printf("\nPlease give number of bits for the code (number>1).\n");
		scanf("%d",&BITSIZEXRHSTH);
	}while(BITSIZEXRHSTH<=1);
	//O arraybit periexei tous kwdikes gray
	arraybit=(int**)malloc(pow(2,BITSIZEXRHSTH)*sizeof(int*));
	if(arraybit==NULL)
	{
		printf("Out of memory.\n");
		return 0;
	}
	for(i=0;i<pow(2,BITSIZEXRHSTH);i++)
	{
		arraybit[i]=(int*)malloc((BITSIZEXRHSTH)*sizeof(int));
		if(arraybit[i]==NULL)
		{
			printf("Out of memory.\n");
			return 0;
		}
	}
	//O binarystring periexei tous kwdikes ascii
	binarystring=(int*)malloc((BITSIZEXRHSTH+1)*sizeof(int));	
	if(binarystring==NULL)
	{
		printf("Out of memory.\n");
		return 0;
	}
	for(i=0;i<BITSIZEXRHSTH+1;i++)
	{
		binarystring[i]='\0';
	}
	//O allzeros arxika einai gematos me 0 kai meta vazoume ton ascii pou den exei 0 sta prwta bit 
	allzeros=(int**)malloc(pow(2,BITSIZEXRHSTH)*sizeof(int*));
	if(allzeros==NULL)
	{
		printf("Out of memory.\n");
		return 0;
	}
	for(allzI=0;allzI<pow(2,BITSIZEXRHSTH);allzI++)
	{
		allzeros[allzI]=(int*)malloc(BITSIZEXRHSTH*sizeof(int));
		if(allzeros[allzI]==NULL)
		{
			printf("Out of memory.\n");
			return 0;
		}
	}
	//Gemizoume to allzeros me 0
	for(allzI=0;allzI<pow(2,BITSIZEXRHSTH);allzI++)
	{
		for(j=0;j<BITSIZEXRHSTH;j++)
		{
			allzeros[allzI][j]=0;
		}
	}
	allzI=0;
	//Dhmiourgoume tous kwdikes ascii
	binary(0,BITSIZEXRHSTH);
	//Ftiaxnoume to aristero dentro
	link2 Tree1=CreateTreeV2(0,pow(2,BITSIZEXRHSTH)-1);
	g=0;
	//Vazoume tous kwdikes gray sta fulla tou aristerou dentrou
	insertLEAFTree1(Tree1);
	//Ftiaxnoume to deksi dentro
	link2 Tree2=CreateTreeV2(0,pow(2,BITSIZEXRHSTH)-1);
	g=pow(2,BITSIZEXRHSTH)-1;
	//Vazoume tous kwdikes gray sta fulla tou deksiou dentrou me antistrofh seira
	insertLEAFTree2(Tree2);
	//Ektupwnoume to aristero dentro
	printf("\nFirst tree with zeros infront of gray.\n");
	print2DUtilV2(Tree1,0);
	//Ektupwnoume to deksi dentro
	printf("\nSecond tree with ones infront of gray.\n");
	print2DUtilV2(Tree2,0);
	//Ftiaxnoume to teliko megalo dentro
	link2 FINAL=(link2)malloc(sizeof(struct node2));
	//Kanoume ta duo prohgoume dentra deksi kai aristero upodentro tou megalou dentrou
	FINAL->left=Tree1;
	FINAL->right=Tree2;
	//Ektupwnoume to teliko megalo dentro
	printf("\nFinal big tree.\n");
	print2DUtilV2(FINAL,0);
	//-------------free-----------------------------
	for(allzI=0;allzI<pow(2,BITSIZEXRHSTH);allzI++)
	{
		free(allzeros[allzI]);
	}
	free(allzeros);
	free(binarystring);
	for(i=0;i<pow(2,BITSIZEXRHSTH);i++)
	{
		free(arraybit[i]);
	}
	free(arraybit);
	free(Q);
	free(T);
	free(Tree1);
	free(Tree2);
	free(FINAL);
	free(root);
	return 0;
}



link new(link l, link r)
{
	int i=0;
	link a=(link)malloc(sizeof(struct node));
	counter++;
	for(i=0;i<BITSIZE;i++)
	{
		a->x[i]=4;
	}
	a->left=l;
	a->right=r;
	if(lol==0)
	{
		root=copy(a);
		lol=1;
	}
	return a;
}



link CreateTree(int l, int r)
{
	int m=(l+r)/2;
	link a=new(NULL,NULL);
	if(l==r)
	{
		return a;
	}
	a->left=CreateTree(l,m);
	a->right=CreateTree(m+1,r);
	return a;
}



link2 newV2(link2 l, link2 r)
{
	int i=0;
	link2 a=(link2)malloc(sizeof(struct node2));
	counter++;
	a->x=(int*)malloc((BITSIZEXRHSTH+1)*sizeof(int));
	if(a->x==NULL)
	{
		printf("Out of memory.\n");
		return 0;
	}
	for(i=0;i<BITSIZEXRHSTH;i++)
	{
		a->x[i]=5;
	}
	a->left=l;
	a->right=r;
	return a;
}



link2 CreateTreeV2(int l, int r)
{
	int m=(l+r)/2;
	link2 a=newV2(NULL,NULL);
	if(l==r)
	{
		return a;
	}
	a->left=CreateTreeV2(l,m);
	a->right=CreateTreeV2(m+1,r);
	return a;
}



void insertLEAF(link t1)
{
	int i;
	if(t1==NULL)
	{
		return;
	}
	else
	{
		if(t1->left==NULL && t1->right==NULL)
		{
			for(i=0;i<BITSIZE;i++)
			{
				t1->x[i]=graycode[g][i];
			}
			if(g==FYLLA)
			{
				return;
			}
			else
			{
				g++;
			}
		}
		insertLEAF(t1->left);
		insertLEAF(t1->right);
	}
}



void insertLEAFV2(link t2)
{
	int i;
	if(t2==NULL)
	{
		return;
	}
	else
	{
		if(t2->left==NULL && t2->right==NULL)
		{
			kladi(root);
			itmp++;
			JJ=0;
			if(g==FYLLA)
			{
				return;
			}
			else
			{
				g++;
			}
		}		
		insertLEAFV2(t2->left);
		insertLEAFV2(t2->right);
	}
}



// Function to find gray from given ascii
void asciitogray(link root1) 
{ 
	int j;
	if(root1==NULL)
  {
	  return; 
  }
  else
  {
		if(root1->left==NULL && root1->right==NULL)
		{
			for(j=0;j<BITSIZE;j++)
			{
				printf("%d",root1->x[j]);
				fprintf(outputfile,"%d",root1->x[j]);
				graytoasciiarray[j]=root1->x[j];
			}
			printf("\n");
		}
		if(chartoasciiarray[i]==0)
  	{
  		i++;
		 	asciitogray(root1->left);
		}
		else if(chartoasciiarray[i]==1)
		{
			i++;
			asciitogray(root1->right);
		}
  }
}



// Function to find gray from given ascii
void graytoascii(link root2) 
{ 
	int j;
	if(root2==NULL)
  {
	  return; 
  }
  else
  {
		if(root2->left==NULL && root2->right==NULL)
		{
			for(j=0;j<BITSIZE;j++)
			{
				printf("%d",root2->x[j]);
			}
			printf("\n");
		}
		if(graytoasciiarray[i]==0)
		{
			i++;
			graytoascii(root2->left);
		}
		else if(graytoasciiarray[i]==1)
		{
			i++;
			graytoascii(root2->right);
		}
  }
}



// Function to print binary link in 2D 
// It does reverse inorder traversal 
void print2DUtil(link root1, int space) 
{ 
    // Base case 
    if(root1==NULL)
    {
       return; 
  	}
  	else
  	{
		  // Increase distance between levels 
		  space += COUNT; 
		  // Process right child first
		  //print2DUtil(root1->left, space); 
		  // Print current node after space 
		  // count 
		  /*printf("\n"); 
		  for (int i=COUNT;i<space;i++)
		  { 
		      printf(" ");    
		  }*/
				int a;
				if(root1->left==NULL && root1->right==NULL)
				{
					for(a=0;a<BITSIZE;a++)
					{
						if(root1->x[a]!=4)
						{
							printf("%d",root1->x[a]); 
						}
					}
					//if(root1->x[a-1]!=4)
					//{
						printf("\n");
					//}
					f++;
				}
		  //Process left child 
		  print2DUtil(root1->left, space); 
		  print2DUtil(root1->right, space);
		}
}



// Function to print binary link in 2D 
// It does reverse inorder traversal 
void print2DUtilV2(link2 root1, int space) 
{ 
    // Base case 
    if(root1==NULL)
    {
       return; 
  	}
  	else
  	{
		  // Increase distance between levels 
		  space += COUNT; 
		  // Process right child first
		  //print2DUtil(root1->left, space); 
		  // Print current node after space 
		  // count 
		  /*printf("\n"); 
		  for (int i=COUNT;i<space;i++)
		  { 
		      printf(" ");    
		  }*/
				int a;
				if(root1->left==NULL && root1->right==NULL)
				{
					for(a=0;a<BITSIZEXRHSTH+1;a++)
					{
						//if(root1->x[a]!=5)
						//{
							printf("%d",root1->x[a]); 
						//}
					}
					//if(root1->x[a-1]!=5)
					//{
						printf("\n");
					//}
					f++;
				}
		  //Process left child 
		  print2DUtilV2(root1->left, space); 
		  print2DUtilV2(root1->right, space);
		}
}



void toASCII(char z)
{
	int i;
	for(i=7;i>=0;--i)
	{
		chartoasciiarray[abs(i-7)]=((z >> i)&1 ? 1 : 0);
	}
}


link copy(link r)
{
	link a=(link)malloc(sizeof(struct node));
	a->left=r->left;
	a->right=r->right;
	return a;
}



link2 copyV2(link2 r)
{
	link2 a=(link2)malloc(sizeof(struct node));
	a->left=r->left;
	a->right=r->right;
	return a;
}



void kladi(link g)
{
	int d=0;
	link h=copy(root);
	while(JJ!=BITSIZE)
	{
		if(graycode[itmp][JJ]==0)
		{
			JJ++;
			h=h->left;
		}	
		else if(graycode[itmp][JJ]==1)
		{
			JJ++;
			h=h->right;
		}
	}
	for(d=0;d<BITSIZE;d++)
	{
		h->x[d]=B[itmp][d];
	}
	return;
}



void gcodes(int n)
{
  int i,j,x=pow(2,n);
  if(n==2)
  {
    arraybit[0][0]=0;
    arraybit[0][1]=0;
    
    arraybit[1][0]=0;
		arraybit[1][1]=1;
		
		arraybit[2][0]=1;
		arraybit[2][1]=1;
		
		arraybit[3][0]=1;
		arraybit[3][1]=0;
  }
  else
  {
  	gcodes(n-1);
    //generate bit j (from n-1 down to 1) for codes up to x-1
    for(i=0,j=n;--j;i=x/2)
    {
    	for(;i<x;i++)
    	{
    		printf(" --1--  i=(%d) x=(%d)\n",i,x);
      	arraybit[i][j]=arraybit[i/2][j-1];
      }
		}
		printf("-------------\n");
    //replicate bit 0 for codes up to x-1
		for(;i<x;i++)
    {
    	printf(" --2--  i=(%d) x=(%d)\n",i,x);
    	arraybit[i][0]=arraybit[i%(x/2)][0];
    }
    /*
    for(i=0;i<x;i++,printf("\n"))
    {
    	for(j=n;j--;)
    	{
      	printf("%d",arraybit[i][j]);
      }
    }*/
  }
}



void insertLEAFTree1(link2 t1)
{
	int i;
	if(t1==NULL)
	{
		return;
	}
	else
	{
		if(t1->left==NULL && t1->right==NULL)
		{
			for(i=1;i<BITSIZEXRHSTH+1;i++)
			{
				t1->x[i]=allzeros[g][i-1];
			}
			t1->x[0]=0;
			if(g==pow(2,BITSIZEXRHSTH))
			{
				return;
			}
			else
			{
				g++;
			}
		}
		insertLEAFTree1(t1->left);
		insertLEAFTree1(t1->right);
	}
}



void insertLEAFTree2(link2 t1)
{
	int i;
	if(t1==NULL)
	{
		return;
	}
	else
	{
		if(t1->left==NULL && t1->right==NULL)
		{
			for(i=1;i<BITSIZEXRHSTH+1;i++)
			{
				t1->x[i]=allzeros[g][i-1];
			}
			t1->x[0]=1;
			if(g==-1)
			{
				return;
			}
			else
			{
				g--;
			}
		}
		insertLEAFTree2(t1->left);
		insertLEAFTree2(t1->right);
	}
}



int decimalToBinary(int decimalnum)
{
    int binarynum = 0;
    int rem, temp = 1;

    while (decimalnum!=0)
    {
        rem = decimalnum%2;
        decimalnum = decimalnum / 2;
        binarynum = binarynum + rem*temp;
        temp = temp * 10;
    }
    return binarynum;
}



int bintogray(int bin)
{
	int s=BITSIZEXRHSTH-1,tmp;
	int a,b,result=0,i=0;
	while(bin!=0)
	{
		a=bin%10;
		bin=bin/10;
		b=bin%10;
		if((a&&!b)||(!a&&b))
		{
			result=result+pow(10,i);
		}
		i++;
	}
	while(result)
	{
		tmp=result%10;
		allzeros[allzI][s]=tmp;
		result/=10;
		s--;
	}
	/*for(s=0;s<BITSIZEXRHSTH;s++)
	{
		printf("%d",allzeros[allzI][s]);
	}
	printf("\n");*/
	allzI++;
	return result;
}


void binary(int index,int length)
{
	int j=0,v,r=0,flag=0;
	if(index==length)
	{
		/*for(j=0;j<BITSIZEXRHSTH;j++)
		{
			printf("%d",binarystring[j]);
		}
		printf("\n");*/
		for(r=0;r<BITSIZEXRHSTH-1;r++)
		{
			if(flag==0)
			{
				v=concat(binarystring[r],binarystring[r+1]);
				flag=1;
			}
			else
			{
				v=concat(v,binarystring[r+1]);
			}
		}
		v=bintogray(v);
		return;
	}
	else
	{
		binarystring[index]=0;
		binary(index+1,length);
		binarystring[index]=1;
		binary(index+1,length);
	}
}



//Function to concatenate 
//two integers into one 
int concat(int a, int b) 
{ 
	char s1[BITSIZEXRHSTH+1]; 
	char s2[BITSIZEXRHSTH+1];  
	//Convert both the integers to string 
	sprintf(s1,"%d",a); 
	sprintf(s2,"%d",b); 
	//Concatenate both strings 
	strcat(s1,s2); 
	//Convert the concatenated string to integer 
	int c=atoi(s1);  
	//return the formed integer 
	return c; 
}











