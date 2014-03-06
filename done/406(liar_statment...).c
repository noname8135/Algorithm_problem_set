#include <stdio.h>

int main()
{
    int flag,i,j,N,C,prime[10001],k=2,prime_count,start_index,end_index;
    prime[0]=1;prime[1]=2;
    for(i=3;i<10000;i+=2)
    {
        for(j=3;j*j<=i;j++)
        if(i%j==0)
        break;
        if(j*j>i)
            prime[k++]=i;
    }
    flag=0;
    while(scanf("%d%d",&N,&C)==2)
    {
        printf("%d %d:",N,C);
        for(prime_count=0;prime[prime_count]<=N;prime_count++)
        ;
        if(prime_count%2)
        {
            if(prime_count>C*2)
            {
                start_index=prime_count/2-C+1;
                end_index=start_index+C*2-2;
            }
            else
            {start_index=0;end_index=prime_count-1;}
        }
        else
        {
            if(prime_count>C*2-1)
            {
                start_index=prime_count/2-C;
                end_index=start_index+C*2-1;
            }
            else
            {start_index=0;end_index=prime_count-1;}
        }
        for(i=start_index;i<=end_index;i++)
            printf(" %d",prime[i]);
        printf("\n\n");
    }
    return 0;
}
