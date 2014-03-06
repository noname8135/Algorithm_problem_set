#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
void divid(int* prime,int* a,int* b)
{
    int i;
    for(i=0;prime[i]<=*a&&prime[i]<=*b;i++)
    if((*a)%prime[i]==0&&(*b)%prime[i]==0)
    {
        *a/=prime[i];
        *b/=prime[i];
        i--;
    }
    return ;
}
int if_prime(int n)
{
    int i;
    for(i=2;i*i<=n;i++)
    if(n%i==0)
    return 0;
    return 1;
}
int main()
{
    int n,m,i,j,prime_count=0;
    int n_ary[1000],m_ary[1000],prime[5000];
    for(i=2;i<10000;i++)
    if(if_prime(i))
    prime[prime_count++]=i;
    while(scanf("%d%d",&n,&m))
    {
        if(!n&&!m)
        return 0;
        else if(m<n/2)
        m=n-m;
        for(i=0;i<n-m;i++)
        n_ary[i]=m+1+i;
        for(i=0;i<n-m-1;i++)
        m_ary[i]=i+2;
        for(i=0;i<n-m-1;i++)
        for(j=0;m_ary[i]!=1;j++)
        divid(prime,n_ary+j,m_ary+i);

        prime_count=1;
        for(i=0;i<n-m;i++)
        prime_count*=n_ary[i];
        printf("%d\n",prime_count);
    }
}
