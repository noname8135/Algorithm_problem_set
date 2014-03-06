#include <stdio.h>
#include <stdlib.h>
int factor(int a,int b)
{
    if(!a)
    return b;
    else if(!b)
    return a;
    return a>=b?factor(a%b,b):factor(a,b%a);
}
int main()
{
    int seed;
    int step,mod;
    while(scanf("%d%d",&step,&mod)!=EOF)
    {
        printf("%10d%10d    ",step,mod);
        if(step==1||factor(step,mod)==1)
        printf("Good Choice\n");
        else
        printf("Bad Choice\n");
        printf("\n");
    }
    return 0;
}
