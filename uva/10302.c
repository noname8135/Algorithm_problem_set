#include <stdio.h>
#include <limits.h>
int main()
{
	long long int sum[50001],i;
	int num;
	sum[0]=0;
	for(i=1;i<=50000;i++)
		sum[i]+=sum[i-1]+i*i*i;
	while(scanf("%d",&num)!=EOF)
	{
		printf("%lld\n",sum[num]);
	}
	return 0;
}