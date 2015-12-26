#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int diff(int a,int b)
{
    return a>b?a-b:b-a;
}
int main()
{
    int next,n,i,m,tot,ary[100],*sum,sum_num,j,*appeared;
    sum=(int*)malloc(sizeof(int)*100000);
    appeared=(int*)malloc(sizeof(int)*100000);
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        for(i=0,tot=0;i<m;i++)
        {
            scanf("%d",&ary[i]);
            tot+=ary[i];
        }
        sum_num=1,sum[0]=0;
        for(i=0;i<=50000;i++)
            appeared[i]=0;
        appeared[0]=1;

        for(i=0;i<m;i++)
        {
            next=0;
            for(j=0;j<sum_num;j++)
            {
                if(!appeared[ary[i]+sum[j]])
                {
                    sum[sum_num+next]=ary[i]+sum[j];
                    next++;
                    appeared[ary[i]+sum[j]]=1;
                }
            }
            sum_num+=next;
        }
        for(i=tot/2;i>=0;i--)
            if(appeared[i])
            break;
        printf("%d\n",tot-i*2);
    }
    return 0;
}
