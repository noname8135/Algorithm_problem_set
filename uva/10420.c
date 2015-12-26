
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct COUNTRY{
	int women;
	char name[100];
}Country;
int cmp(const void* a,const void* b)
{
	Country aa=*((Country*)a),bb=*((Country*)b);
	return strcmp(aa.name,bb.name);
}
int main()
{
	int n,i,counter=0,women[2001];
	Country country[2001];
	char tmp[100],now[100];
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
		country[i].women=0;
	while(n--)
	{
		fgets(tmp,99,stdin);
		sscanf(tmp,"%s",now);
		for(i=0;i<counter;i++)
			if(!strcmp(country[i].name,now))
			{
				country[i].women++;
				break;
			}
		if(i==counter)
		{
			strcpy(country[counter].name,now);
			country[counter++].women=1;
		}
	}
	qsort(country,counter,sizeof(Country),cmp);
	for(i=0;i<counter;i++)
		printf("%s %d\n",country[i].name,country[i].women);
	return 0;
}