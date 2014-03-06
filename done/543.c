#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int if_prime(int n)
{
    int i;
    for(i=3;i*i<=n;i+=2)
    if(n%i==0)
    return 0;
    return 1;
}
int main()
{
    bool *prime;
    int n,i,count=0;
    prime=(bool*)malloc(sizeof(bool)*600000);
    for(n=3;n<1000002;n+=2)
    if(if_prime(n))
    prime[n/2-1]=1;
    restart:
    while(scanf("%d",&n)&&n)
    {
        for(i=3;i<=1000001;i+=2)
        if(prime[i/2-1]&&prime[(n-i)/2-1])
        {
            printf("%d = %d + %d\n",n,i,n-i);
            goto restart;
        }
        printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
