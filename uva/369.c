#include <stdio.h>
int is_prime(int n)
{
    int i;
    for(i=2;i*i<=n;i++)
    if(n%i==0)
    return 0;
    return 1;
}
void common_divis(int* a,int* b,int* prime,int prime_total_num)
{
    int i;
    for(i=0;prime[i]<=*a&&prime[i]<=*b&&i<prime_total_num;i++)
    if(*a%prime[i]==0&&*b%prime[i]==0)
    {*a/=prime[i];*b/=prime[i--];}
    return ;
}
int main()
{
    int j,N,M,mul_ele[100],i,divisor[100],prime[40],prime_total_num;
    for(i=2,prime_total_num=0;i<100;i++)
    if(is_prime(i))
    prime[prime_total_num++]=i;
    while(scanf("%d%d",&N,&M)&&N!=0&&M!=0)
    {
        printf("%d things taken %d at a time is ",N,M);
        for(i=0;i<N-M-1;i++)
        divisor[i]=i+2;
        for(i=0;i<N-M;i++)
        mul_ele[i]=M+1+i;
        for(i=0;i<N-M-1;i++)
        {
            for(j=0;j<N-M;j++)
            common_divis(mul_ele+j,divisor+i,prime,prime_total_num);
        }
        for(i=1,j=0;j<N-M;j++)
        i*=mul_ele[j];
        printf("%d exactly.\n",i);
    }
    return 0;
}
