#include <stdio.h>
#include <stdbool.h>
typedef struct fwfw
{
	int a,b,c;
}CONST ;

CONST constrain[20];
int counter,pos[8];

bool judge(int* student,int n)
{
	int i,diff;
	for(i=0;i<n;i++)
	{
		diff=pos[constrain[i].a]-pos[constrain[i].b];
		if(diff<0)
			diff=-diff;
		if(constrain[i].c<0&&diff<-(constrain[i].c))
			return 0;
		else if(constrain[i].c>0&&diff>constrain[i].c)
			return 0;
	}
	return 1;
}
void per(int* student,int cur,int n,bool* used,int constrain_num)
{
	int i;
	if(cur==n)
	{
		for(i=0;i<n;i++)
		pos[student[i]]=i;

		if(judge(student,constrain_num))
			counter++;
		return ;
	}
	for(i=0;i<n;i++)
	{
		if(!used[i])
		{
			used[i]=1;
			student[cur]=i;
			per(student,cur+1,n,used,constrain_num);
			used[i]=0;
		}
	}
	return ;
}
int main()
{
	int m,n,student[8],i;
	bool used[8];
	for(i=0;i<8;i++)
		used[i]=0;
	while(scanf("%d%d",&m,&n)&&(m||n))
	{
		counter=0;
		for(i=0;i<n;i++)
			scanf("%d%d%d",&(constrain[i].a),&(constrain[i].b),&(constrain[i].c));
		per(student,0,m,used,n);
		printf("%d\n",counter);
	}
	return 0;
}