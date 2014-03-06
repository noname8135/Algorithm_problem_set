#include <stdio.h>

int main()
{
	int n,N,i,M,relation[30001],a,b,root_a,root_b,max;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&N,&M);
		for(i=1;i<=N;i++)
			relation[i]=0;
		max=0;
		while(M--)
		{
			scanf("%d%d",&a,&b);
			root_a=a;root_b=b;
			while(relation[root_a]>0)
				root_a=relation[root_a];
			while(relation[root_b]>0)
				root_b=relation[root_b];
			
			if(relation[root_a]==0&&relation[root_b]==0)
			{
				relation[root_a]=root_b;
				relation[root_b]=-2;
			}
			else if(relation[root_a]==0)
			{
				relation[root_a]=root_b;
				relation[root_b]-=1;
			}
			else if(relation[root_b]==0)
			{
				relation[root_b]=root_a;
				relation[root_a]-=1;
			}
			else if(root_a!=root_b)
			{
				relation[root_b]+=relation[root_a];
				relation[root_a]=root_b;
			}
			//printf("roota=%d %drootb=%d %d\n",root_a,relation[root_a],root_b,relation[root_b]);
			if(relation[root_a]<max)
				max=relation[root_a];
			if(relation[root_b]<max)
				max=relation[root_b];
		}
		printf("%d\n",max*-1);
	}
}