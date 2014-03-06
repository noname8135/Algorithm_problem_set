#include<stdlib.h>
#include<stdio.h>
int main()
{
    int i,cost[5]={5,10,25,50};
    int money[2000],a,b,n;
    for(i=0;i<1800;i++)
        money[i]=1;
    for(a=0;a<4;a++)
    for(b=cost[a]/5;b<1800;b++)
        money[b]+=money[b-cost[a]/5];
    while(scanf("%d",&n)==1)
    printf("%d\n",money[n/5]);
    return 0;
}
