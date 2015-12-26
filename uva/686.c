#include <stdio.h>

int main()
{
	int i,j,prime[3600],prime_count=1;
	prime[0]=2;
	for(i=3;prime_count<3600;i++)
	{
		for(j=0;prime[j]*prime[j]<=i;j++)
		if(i%prime[j]==0)
			break;
		if(prime[j]*prime[j]>i)
			prime[prime_count++]=i;
	}

	int n,counter;
	while(scanf("%d",&n)&&n)
	{
		counter=0;
		for(i=0;prime[i]<=n/2;i++)
		{
			for(j=0;prime[j]<=n;j++)
			if(prime[i]+prime[j]==n)
			{
				//printf("%d + %d \n",prime[i],prime[j]);
				counter++;
				break;
			}
		}
		printf("%d\n",counter);
	}
	return 0;
}