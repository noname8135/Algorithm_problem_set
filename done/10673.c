#include <stdio.h>
#include <stdbool.h>
int main()
{
    int n,x,k,i,j,num1,num2;
    bool found;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&x,&k);
        num1=x/k;
        if(num1*k==x)
        num2=num1;
        else
        num2=num1+1;
        found=0;
        for(i=0;;i++)
        {
            for(j=0;num1*i+num2*j<=x;j++)
                if(num1*i+num2*j==x)
                {
                    found=1;
                    break;
                }
            if(found)
                break;
        }
        printf("%d %d\n",i,j);
    }
    return 0;
}
