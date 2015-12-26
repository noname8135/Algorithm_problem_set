#include <stdio.h>

int main()
{
	int t,n,i,high,low,last,j,tmp;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Case %d: ",i);
		scanf("%d",&n);
		high=0,low=0;
		last=-1;
		for(j=0;j<n;j++)
		{
			scanf("%d",&tmp);
			if(last!=-1)
			{
				if(last<tmp)
				high++;
				else if(last>tmp)
				low++;
			}
			last=tmp;
		}
		printf("%d %d\n",high,low);

	}
}