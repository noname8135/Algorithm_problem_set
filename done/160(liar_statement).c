#include <stdio.h>
#include <string.h>
int if_prime(int n)
{
    int i;
    for(i=2;i*i<=n;i++)
    if(n%i==0)
    return 0;
    return 1;
}
void add_prime_happen(int *prime,int* prime_happen,int num)
{
    int i;
    for(i=0;num!=1;i++)
    if(num%prime[i]==0)
    {
        num/=prime[i];
        prime_happen[i]++;
        i--;
    }
    return ;
}
int main()
{
    int factorial,prime[30],tmp,prime_count=0,i,prime_happen[30];
    for(tmp=2;tmp<103;tmp++)
    if(if_prime(tmp))
    prime[prime_count++]=tmp;
    while(scanf("%d",&factorial)&&factorial)
    {
        printf("%3d! =",factorial);
        memset(prime_happen,0,sizeof(int)*prime_count);
        for(i=2;i<=factorial;i++)
        add_prime_happen(prime,prime_happen,i);
        for(i=0;prime_happen[i]!=0;i++)
        {
            if(i&&i%15==0)
            printf("\n      ");
            printf("%3d",prime_happen[i]);
        }
        printf("\n");
    }
    return 0;
}
