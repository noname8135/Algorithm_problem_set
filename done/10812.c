#include <stdio.h>

int main()
{
    int a,b,n,sum,dif;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&sum,&dif);
        a=(sum+dif)/2;
        if((b=sum-a)<0||sum<0||(sum%2&&!(dif%2))||(dif%2&&!(sum%2))||dif<0)
        printf("impossible");
        else if (a>b)
        printf("%d %d",a,b);
        else
        printf("%d %d",b,a);
        printf("\n");
    }
    return 0;
}
