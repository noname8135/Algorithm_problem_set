#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int cmp(const void* a,const void* b)
{
	return *((char*)a)-*((char*)b);
}
void dfs(char str[],char collect[],int n,int cur,bool used[])
{
	if(cur==n)
	{
		collect[n]='\0';
		printf("%s\n",collect);
		return ;
	}
	int i;
	char last='\0';
	for(i=0;i<n;i++)
	{
		if(str[i]!=last&&used[i]==0)
		{
			used[i]=1;
			last=str[i];
			collect[cur]=str[i];
			dfs(str,collect,n,cur+1,used);
			used[i]=0;
		}
	}
	return ;
}

int main()
{
	int n,i;
	char str[20],collect[20];
	bool used[20];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",str);
		qsort(str,strlen(str),sizeof(char),cmp);
		for(i=0;i<strlen(str);i++)
			used[i]=0;
		dfs(str,collect,strlen(str),0,used);
		printf("\n");
	}
	return 0;
}