#include <stdio.h>

int main()
{
	char tmp[200];
	int sum,i;
	
	while(fgets(tmp,199,stdin))
	{
		sum=0;
		for(i=0;tmp[i]!='\0';i++)
		{
			if(tmp[i]>='a'&&tmp[i]<='z')
				sum+=tmp[i]-'a'+1;
			else if(tmp[i]>='A'&&tmp[i]<='Z')
				sum+=tmp[i]-'A'+27;
		}
		for(i=2;i*i<=sum;i++)
			if(sum%i==0)
			break;
		if(i*i>sum)
			printf("It is a prime word.\n");
		else
			printf("It is not a prime word.\n");
	}
	return 0;
}