#include <stdio.h>

int main()
{
	int n,humble_count=1,walker[4];
	long long int humble[6000],num[4];
	humble[0]=1;
	walker[0]=0,walker[2]=0,walker[1]=0,walker[3]=0;
	while(humble_count<=5842)
	{
		num[0]=humble[walker[0]]*2;
		num[1]=humble[walker[1]]*3;
		num[2]=humble[walker[2]]*5;
		num[3]=humble[walker[3]]*7;
		if(num[0]<=num[1]&&num[0]<=num[2]&&num[0]<=num[3])
		{
			humble[humble_count]=num[0];
			walker[0]++;
		}
		else if(num[1]<=num[0]&&num[1]<=num[2]&&num[1]<=num[3])
		{
			humble[humble_count]=num[1];
			walker[1]++;
		}
		else if(num[2]<=num[1]&&num[2]<=num[0]&&num[2]<=num[3])
		{
			humble[humble_count]=num[2];
			walker[2]++;
		}
		else if(num[3]<=num[1]&&num[3]<=num[2]&&num[3]<=num[0])
		{
			humble[humble_count]=num[3];
			walker[3]++;
		}
		if(humble[humble_count]!=humble[humble_count-1])
			humble_count++;
	}
	while(scanf("%d",&n)&&n)
	{
		printf("The %d",n);
		if(n%100<10||n%100>20)
		{
			if(n%10==1)
			printf("st ");
			else if(n%10==2)
			printf("nd ");
			else if(n%10==3)
			printf("rd ");
			else
			printf("th ");
		}
		else
			printf("th ");
		printf("humble number is %lld.\n",humble[n-1]);
	}
	return 0;
}