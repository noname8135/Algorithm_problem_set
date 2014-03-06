#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct UOONO{
	int A,B,cost;
	char name[20];
}AGENCY;
int cmp(const void* a,const void* b)
{
	AGENCY agency_a=*((AGENCY *)a),agency_b=*((AGENCY *)b);
	if(agency_a.cost!=agency_b.cost)
		return agency_a.cost-agency_b.cost;
	return strcmp(agency_a.name,agency_b.name);
}
int costs(AGENCY agency,int now,int target)
{
	int cost=0,next;
	while(now!=target)
	{
		next=now/2;
		if(next<target||(now-next)*agency.A<agency.B)
		{
			cost+=agency.A*(now-target);
			now=target;
		}
		else 
		{
			cost+=agency.B;
			now=next;
		}
	}
	return cost;
}
int main()
{
	AGENCY agency[101];
	char input[100];
	int n,now,target,m,j,i,case_count;
	scanf("%d",&n);
	for(case_count=1;case_count<=n;case_count++)
	{
		printf("Case %d\n",case_count);
		scanf("%d%d%d\n",&now,&target,&m);
		for(i=0;i<m;i++)
		{
			fgets(input,99,stdin);
			for(j=0;input[j]!=':';j++)
			if(input[j]>='A'&&input[j]<='Z')
				agency[i].name[j]=input[j];
			agency[i].name[j]='\0';
			sscanf(input+j+1,"%d",&(agency[i].A));
			for(;input[j]!=',';j++)
				;
			sscanf(input+j+1,"%d",&(agency[i].B));
		}
		for(i=0;i<m;i++)
			agency[i].cost=costs(agency[i],now,target);
		qsort(agency,m,sizeof(AGENCY),cmp);
		for(i=0;i<m;i++)
			printf("%s %d\n",agency[i].name,agency[i].cost);
	}
	return 0;
}