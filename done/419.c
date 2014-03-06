#include <stdio.h>
#include <math.h>
int common_fac(int a,int b)
{
    if(!a||!b)
    return (a==0)?b:a;
    return a>b?common_fac(a%b,b):common_fac(a,b%a);
}
int main()
{
    int counter,n,num[51],i,j,pair_count;
    while(scanf("%d",&n))
    {if(!n)
    return 0;
    counter=0;pair_count=0;
    for(i=0;i<n;i++)
    scanf("%d",&num[i]);
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    {if(common_fac(num[i],num[j])==1)
    counter++;pair_count++;}
   // printf("counter=%d pair_count=%d\n",counter,pair_count);
    if(counter==0)
    printf("No estimate for this data set.\n");
    else
    printf("%.6lf\n",sqrt((double)((double)pair_count/(double)(counter)*6)));
    }
}
