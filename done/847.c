#include <stdio.h>

int main()
{
	long long int num,p;
	int flag;

	while(scanf("%lld",&num)!=EOF)
	{
		p=1,flag=0;
		while(p<num)
		{
			p*=9;
			flag=1;
			if(p>=num)
			break;
			p*=2;
			flag=0;
		}
		if(flag)
		printf("Stan wins.\n");
		else
		printf("Ollie wins.\n");
	}
	return 0;
}