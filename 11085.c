#include <stdio.h>
#include <stdbool.h>
bool judge(int* num)	//if it's a successful 8 queen map
{
	int i,j;
	for(i=0;i<7;i++)
	{
		for(j=i+1;j<8;j++)
			if(j-i==num[j]-num[i]||j-i==num[i]-num[j])
			return 0;
	}
	return 1;
}
int success[500][8],counter=0;
void per(int* num,int cur,int n,bool* used)
{
	int i;
	if(cur==n)
	{
		if(judge(num))
		{
			for(i=0;i<8;i++)
			success[counter][i]=num[i];
			counter++;
		}
		return;
	}
	for(i=0;i<8;i++)
	{
		if(!used[i])
		{
			used[i]=1;
			num[cur]=i;
			per(num,cur+1,n,used);
			used[i]=0;
		}
	}
	return;
}
int main()
{
	bool used[8]={0};
	int num[8],cur,n=8,min,a[8],case_count=0,i,j,move;
	per(num,0,n,used);
	while(scanf("%d",&a[0])!=EOF)
	{
		a[0]--;
		for(i=1;i<8;i++)
			{
				scanf("%d",&a[i]);
				a[i]--;
			}
		min=8;
		for(i=0;i<counter;i++)
		{
			move=0;
			for(j=0;j<8;j++)
			{
				if(a[j]!=success[i][j])
				move++;
			}
			if(move<min)
				min=move;
		}
		printf("Case %d: %d\n",++case_count,min);
	}
	return 0;
}