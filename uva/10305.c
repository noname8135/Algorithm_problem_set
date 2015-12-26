#include <stdio.h>
#include <stdbool.h>

typedef struct TREE{
	int value;
	int depend;
}Tree;
int counter;
void travel(Tree *tree,Tree node,bool* mentioned,int n)
{
	if(node.depend!=-1)
	travel(tree,tree[node.depend],mentioned,n);

	if(!mentioned[node.value])
	{
		if(counter!=n-1)
		printf("%d_",node.value);
		else
		printf("%d\n",node.value);
		counter++;
	}
	mentioned[node.value]=1;
	return;
}

int main()
{
	int n,m,i,a,b;
	Tree tree[101];
	bool mentioned[101];
	while(scanf("%d%d",&n,&m)&&(n||m))
	{
		for(i=1;i<=n;i++)
		{
			mentioned[i]=0;
			tree[i].depend=-1;
			tree[i].value=i;
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			tree[b].depend=a;
		}
		counter=0;
		for(i=1;i<=n;i++)
			travel(tree,tree[i],mentioned,n);
	}
	return 0;
}