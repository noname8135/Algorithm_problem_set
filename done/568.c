#include <stdio.h>
int main()
{
    int n,i,a[10000];
    long long int temp=1;
    for(i=1;i<=9999;i++)
    {
        temp*=i;
        while(!(temp%10))
        temp/=10;
        a[i-1]=temp%10;
        temp%=1000000;  //get enough digits to not influence the result
    }
    while(scanf("%d",&n)!=EOF)
    {
        printf("%5d -> %d\n",n,a[n-1]);
    }
    return 0;
}
