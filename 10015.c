#include <stdio.h>

int main()
{
    int n,a[3600],i,prime[4000],counter,j,walker;
    prime[0]=2;counter=1;
    for(i=3;counter<4000;i+=2)
    {
        for(j=0;prime[j]*prime[j]<=i;j++)
        if(i%prime[j]==0)
        break;
        if(prime[j]*prime[j]>i)
            prime[counter++]=i;
    }
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)
        a[i]=i+1;
        i=0;walker=0;
        while(n>1)
        {
            walker+=prime[i++]-1;
            if(walker>=n)
            walker%=n;
            for(j=walker;j<n-1;j++)
            a[j]=a[j+1];
            n--;
        }
        printf("%d\n",a[0]);
    }
    return 0;
}
