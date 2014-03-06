#include <stdio.h>
int main()
{
	long long int way[50001];

	int num;
	way[0]=1;
	way[1]=2;
	for(num=2;num<=50;num++)
		way[num]=way[num-1]+way[num-2];
	while(scanf("%d",&num)&&num)
	{
		printf("%lld\n",way[num-1]);
	}
	return 0;
}