#include <stdio.h>
#include <string.h>
int main()
{
	int i,len;
	char str[100001],rev[100001];
	while(scanf("%s",str)!=EOF)
	{
		len=strlen(str);
		for(i=len-1;i>=0;i--)
			rev[len-1-i]=str[i];
		rev[len]='\0';
		for(i=0;i<len;i++)
			if(!strncmp(str+i,rev,len-i))
				break;
		printf("%s%s\n",str,rev+len-i);
	}
	return 0;
}