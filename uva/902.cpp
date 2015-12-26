#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <iostream>
using namespace std;

int main()
{
	char *str,tmp[11],ans[11];
	int n,counter,i,j,max,index,k;

	map<string,int> appeared;

	str=(char*)malloc(sizeof(char)*1000000);

	while(scanf("%d",&n)!=EOF)
	{
		appeared.clear();
		scanf("%s",str);
		counter=0;max=0;
		for(i=0;str[i+n-1]!='\0';i++)
		{
				strncpy(tmp,str+i,n);
				tmp[n]='\0';
				appeared[tmp]++;
				if(max<appeared[tmp])
					{
						max=appeared[tmp];
						strcpy(ans,tmp);
					}
		}
		printf("%s\n",ans);
	}
	return 0;
}