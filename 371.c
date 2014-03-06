#include <stdio.h>

int main()
{
	int length,max_len;
	long long int max,H,L,i,walker,tmp;
	while(scanf("%lld%lld",&L,&H)&&(L||H))
	{
		max_len=0;
		if(L>H)
		{
			tmp=L;
			L=H;
			H=tmp;
		}
		for(i=L;i<=H;i++)
		{
			walker=i;
			length=0;
			while(1)
			{
				if(walker%2)
					walker=3*walker+1;
				else
					walker/=2;
				length++;
				if(walker==1)
					break;
			}
			if(length>max_len)
				{
					max_len=length;
					max=i;
				}
		}
		printf("Between %lld and %lld, %lld generates the longest sequence of %d values.\n",L,H,max,max_len);
	}
	return 0;
}