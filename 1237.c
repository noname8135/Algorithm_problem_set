#include <stdio.h>
typedef struct fenrfne
{
	char name[21];
	int L,H;
}MANU;
int main()
{
	MANU manu[10000];
	int index,i,T,D,n,price,highest,lowest,counter;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&D);
		highest=0;lowest=1000000;
		for(i=0;i<D;i++)
			{
				scanf("%s %d %d",manu[i].name,&manu[i].L,&manu[i].H);
				if(manu[i].L<lowest)
					lowest=manu[i].L;
				if(manu[i].H>highest)
					highest=manu[i].H;
			}
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&price);
			if(price>highest||price<lowest)
				printf("UNDETERMINED\n");
			else
			{
				for(i=0,counter=0;i<D;i++)
				{
					if(price<=manu[i].H&&price>=manu[i].L)
						{counter++;index=i;}
					if(counter==2)
						break;
				}
				if(counter==2||counter==0)
					printf("UNDETERMINED\n");
				else
					printf("%s\n",manu[index].name);
			}
			if(!n&&T)
				printf("\n");
		}
	}
	return 0;
}