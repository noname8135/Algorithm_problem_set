#include <stdio.h>

int main()
{
    int flag,n,j,tmp,i,ary[10000];
    while(scanf("%d",&n)&&n)
    {
        flag=0;
        for(i=0,j=0;i<n;i++)
        {
            scanf("%d",&tmp);
            if(tmp)
            {
                flag=1;
                ary[j++]=tmp;
            }
        }
        if(!flag)
            printf("0\n");
        else
        for(i=0;i<j;i++)
            if(i!=j-1)
            printf("%d ",ary[i]);
            else
            printf("%d\n",ary[i]);
    }
    return 0;
}
