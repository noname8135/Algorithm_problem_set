#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
using namespace std;
int main()
{
	char tmp[20],order[10][20];
	int person_num,give,n,i,j,get,first=1;
	map<string,int> money;
	while(scanf("%d",&person_num)!=EOF)
	{
		money.clear();
		for(i=0;i<person_num;i++)
		{
			scanf("%s",order[i]);
			money[order[i]]=0;
		}
		for(i=0;i<person_num;i++)
		{
			scanf("%s",tmp);
			scanf("%d %d",&give,&n);
			if(n)
			{
				get=give/n;
				money[tmp]-=get*n;
				for(j=0;j<n;j++)
				{
					scanf("%s",tmp);
					money[tmp]+=get;
				}
			}
		}
		if(!first)
		printf("\n");
		else
		first=0;
		for(i=0;i<person_num;i++)
		{
			printf("%s %d\n",order[i],money[order[i]]);
		}
	}
	return 0;
}