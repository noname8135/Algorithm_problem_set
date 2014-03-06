#include <stdio.h>

int main()
{
    int n,m,ary[1001],i,target,closest,j,cas_count=0,num;
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)
            scanf("%d",&ary[i]);
        scanf("%d",&m);
        printf("Case %d:\n",++cas_count);
        while(m--)
        {
        scanf("%d",&target);
        closest=2147483647;
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
            {
                if(ary[i]+ary[j]>target)
                {
                    if(ary[i]+ary[j]-target<closest)
                        {
                            closest=ary[i]+ary[j]-target;
                            num=ary[i]+ary[j];
                        }
                }
                else
                {
                    if(target-ary[i]-ary[j]<closest)
                        {
                            closest=target-ary[i]-ary[j];
                            num=ary[i]+ary[j];
                        }
                }
            }
        printf("Closest sum to %d is %d.\n",target,num);}
    }
    return 0;
}
