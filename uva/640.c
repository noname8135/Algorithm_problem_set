#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int gen(int num)
{
    int tmp=num,sum=0;
    while(tmp)
    {
        sum+=tmp%10;
        tmp/=10;
    }
    return num+sum;
}
int main()
{
    bool* num;
    int i;
    num=(bool*)malloc(sizeof(bool)*1100000);
    for(i=0;i<1100000;i++)
    num[i]=0;

    for(i=1;i<1000000;i++)
    num[gen(i)]=1;

    for(i=1;i<=1000000;i++)
    if(!num[i])
    printf("%d\n",i);
    return 0;
}
