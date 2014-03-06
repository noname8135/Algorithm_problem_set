#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int main()
{
    int i,j,k=1;
    long long int num,tmp;
    int *prime;
    prime=(int*)malloc(sizeof(int)*50000);
    prime[0]=2;
    for(i=3;i<50000;i+=2)
    {
        for(j=2;j*j<=i;j++)
        if(i%j==0)
        break;
        if(j*j>i)
            prime[k++]=i;
    }
    while(scanf("%lld",&num)&&num)
    {
        printf("%lld = ",num);
        if(num==1)
        {
            printf("1\n");
            continue;
        }
        else if(num==-1)
        {
            printf("-1\n");
            continue;
        }
        else if(num<0)
            {
                printf("-1 x ");
                num*=-1;
            }
        tmp=num;
        for(i=0;num>1&&i<k;i++)
            if(num%prime[i]==0)
            {
                printf("%d",prime[i]);
                num/=prime[i];
                break;
            }
        for(;num>1&&i<k;i++)
            if(!(num%prime[i]))
            {
                printf(" x %d",prime[i]);
                num/=prime[i--];
            }
        if(i==k&&tmp!=num)
        printf(" x %lld",num);
        else if(i==k&&tmp==num)
            printf("%lld",num);
        printf("\n");
    }
    return 0;
}
