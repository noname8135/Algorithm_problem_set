#include <stdio.h>
int fac_tot(int num)
{
    int i,adder=1;
    for(i=2;i*i<num;i++)
    if(num%i==0)
    {
        adder+=i;adder+=num/i;
    }
    if(i*i==num)
    adder+=i;
    return adder;
}
int main()
{
    int n,tmp;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n)&&n)
    {
        printf("%5d  ",n);
        tmp=fac_tot(n);
        if(n==1)
        printf("DEFICIENT\n");
        else if(tmp==n)
        printf("PERFECT\n");
        else if(tmp<n)
        printf("DEFICIENT\n");
        else
        printf("ABUNDANT\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
