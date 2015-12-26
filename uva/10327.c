#include <stdio.h>
#include <stdbool.h>
int main()
{
    int tmp,n,i,ary[1001],xchange_count;
    bool xchange;
    while(scanf("%d",&n)!=EOF)
    {
        xchange_count=0;
        xchange=1;
        for(i=0;i<n;i++)
            scanf("%d",&ary[i]);
        while(xchange){
            xchange=0;
            for(i=0;i<n-1;i++)
                if(ary[i]>ary[i+1]){
                    tmp=ary[i];
                    ary[i]=ary[i+1];
                    ary[i+1]=tmp;
                    xchange=1;
                    xchange_count++;
        }
        }
        printf("Minimum exchange operations : %d\n",xchange_count);
    }
    return 0;
}
