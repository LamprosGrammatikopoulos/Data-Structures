#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	double x;
	double y;
	double z;
}vector;
vector* vector_add(vector *a, vector *b);
vector* vector_subtract(vector *a, vector *b);
vector* vector_product(vector *a, double k);
double vector_inner_product(vector *a, vector *b);
vector* vector_cross_product(vector *a, vector *b);
double vector_norm(vector *a);
int vector_equal(vector *a, vector *b);
int vector_parallel(vector *a, vector *b);
int vector_normal(vector *a, vector *b);
int main(void)
{
	vector *a,*b,*sum;
	sum=(vector*)malloc(sizeof(vector));
	a=(vector*)malloc(sizeof(vector));
	b=(vector*)malloc(sizeof(vector));
	int n=0;
	int h1=0,h2=0,h3=0;
	double c1=0,c2=0,k=0;
	do
	{	
		printf("|----------------------------------------|\n");
		printf("| Entoles:                               |\n");
		printf("|----------------------------------------|\n");
		printf("| 0-Termatismos programmatos.            |\n");
		printf("| 1-Prosthesh dianusmatwn.               |\n");
		printf("| 2-Afairesh dianusmatwn.                |\n");
		printf("| 3-Ginomeno dianusmatos me arithmo.     |\n");
		printf("| 4-Eswteriko ginomeno.                  |\n");
		printf("| 5-Ekswteriko ginomeno.                 |\n");
		printf("| 6-Metro dianusmatos.                   |\n");
		printf("| 7-Elegxos isothtas dianusmatwn.        |\n");
		printf("| 8-Elegxos suggramikothtas dianumsatwn  |\n");
		printf("| 9-Elegxos kathetothtas dianusmatwn.    |\n");
		printf("|----------------------------------------|\n");
		printf("\nDwste arithmo entolhs: ");
		scanf("%d",&n);
		if(n!=0 && n!=1 && n!=2 && n!=3 && n!=4 && n!=5 && n!=6 && n!=7 && n!=8 && n!=9)
		{
			printf("Dwste enan akeraio arithmo entolhs pou na periexetai sto diasthma [0,9].\n");
		}
		switch(n)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				printf("Dwste tis suntetagmenes gia duo dianusmata me thn morfh: x1,y1,z1 x2,y2,y3 .\n");
				scanf("%lf,%lf,%lf %lf,%lf,%lf",&(a->x),&(a->y),&(a->z),&(b->x),&(b->y),&(b->z));
				vector* sum=vector_add(a,b);
				printf("To dianusma pou prokuptei exei tis metablhtes: %lf,%lf,%lf .\n",(sum->x),(sum->y),(sum->z));
				break;
			}
			/*case 2:
			{
				vector* sum=vector_subtract(&a,&b);
				break;
			}
			case 3:
			{
				vector* sum=vector_product(&a,k);
				break;
			}
			case 4:
			{
				double c1=vector_inner_product(&a,&b);
				break;
			}
			case 5:
			{
				vector* sum=vector_cross_product(&a,&b);
				break;
			}
			case 6:
			{
				double c2=vector_norm(&a);
				break;
			}
			case 7:
			{
				int h1=vector_equal(&a,&b);
				break;
			}
			case 8:
			{
				int h2=vector_parallel(&a,&b);
				break;
			}
			case 9:
			{
				int h3=vector_normal(&a,&b);
				break;
			}*/		
		}	
	}while(n!=0);
	free(sum);
	free(a);
	free(b);
	return 0;
}



vector* vector_add(vector *a, vector *b)
{
	vector *sum;
	sum=(vector*)malloc(sizeof(vector));
	(sum->x)=(a->x)+(b->x);
	(sum->y)=(a->y)+(b->y);
	(sum->z)=(a->z)+(b->z);
	return sum;
}






















