#include <stdio.h>

int main()
{
    int tmp,x1,x2,num,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&num);
        x1=0;x2=0;tmp=num;
        while(num>0)
        {
            if(num%2)
            x1++;
            num/=2;
        }
        num=tmp;
        while(num>0)
        {
            tmp=num%10;
            while(tmp>0)
            {
                if(tmp%2)
                x2++;
                tmp/=2;
            }
            num/=10;
        }
        printf("%d %d\n",x1,x2);
    }
    return 0;
}
