#include <stdio.h>

int main()
{
    int pos,zero,n,case_count=0,num;
    while(scanf("%d",&n)&&n)
    {
        pos=0;zero=0;
        while(n--)
        {
            scanf("%d",&num);
            if(num>0)
            pos++;
            else
            zero++;
        }
        printf("Case %d: %d\n",++case_count,pos-zero);
    }
    return 0;
}
