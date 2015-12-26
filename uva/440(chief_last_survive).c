#include <stdio.h>

int main()
{
	int step,walker,n,total;
	while(scanf("%d",&n)&&n)
	{
		for(step=2;;step++)
		{
			walker=step-1;
			total=n-1;
			while(1)
			{
				walker%=total;
				if(walker==0)
				break;
				walker+=step-1;
				total--;
			}
			if(total==1)
			{
				printf("%d\n",step);
				break;
			}
		}
	}
	return 0;
}