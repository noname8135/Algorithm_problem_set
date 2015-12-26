#include <stdio.h>
int main()
{
    int k,limit,m,position,counter,ans[15];
    for(k=1;k<14;k++)
    {for(m=k+1;;m++)
        {
            limit=2*k;
            if((m-1)%limit<k)
                {
                    m+=k-1;
                    continue;
                }
            for(position=(m-1)%limit;limit>k;position=(position+m)%limit)
            {
                if(position<k)
                    break;
                position--;
                limit--;
            }
            if(limit==k)
                break;
        }
    ans[k-1]=m;
    }
    while(scanf("%d",&k)&&k)
    {
        printf("%d\n",ans[k-1]);
    }
    return 0;
}
