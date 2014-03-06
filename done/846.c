#include <stdio.h>
#include <math.h>
long long int fn(long long int n)
{
	if(n%2)
		return (n*n+2*n+1)/4;
	else
		return (n*n+2*n)/4;
}
int main()
{
	int x,y,n;
	long long int step,dis;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&x,&y);
		dis=y-x;
		if(dis<0)
			dis=dis*-1;
		step=((long long int)sqrt(4*dis+1))-1;
        if(fn(step)>=dis)
		printf("%d\n",step);
		else if(fn(step+1)>=dis)
        printf("%d\n",step+1);
	}
	return 0;
}
