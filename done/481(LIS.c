#include <stdio.h>

int main()
{
	int num[100000],tmp[100000],rank[100000];
	int num_count=0;
	while(scanf("%d",&num[num_count])!=EOF)
	{
		num_count++;
	}
	int j,i,tmp_count;
	tmp_count=1;
	tmp[0]=num[0];
	rank[0]=0;
	for(i=1;i<num_count;i++)
		{
			for(j=0;j<tmp_count;j++)
				if(num[i]<=tmp[j])
				{
					rank[i]=j;
					tmp[j]=num[i];
					break;
				}
			if(j==tmp_count)
			{
				rank[i]=tmp_count;
				tmp[tmp_count++]=num[i];
			}
		}
	int last_query=num_count-1,ans[100000],ans_count=0;
	for(i=tmp_count-1;i>=0;i--)
		for(j=last_query;j>=0;j--)
		{
			if(rank[j]==i)
			{
				last_query=j;
				ans[ans_count++]=num[j];
				break;
			}
		}
		printf("%d\n-\n",ans_count);
	for(i=ans_count-1;i>=0;i--)
		{
			printf("%d\n",ans[i]);
		}
	return 0;
}