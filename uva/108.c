#include <stdio.h>
#include <limits.h>
int max_con_sum(int ary[][101],int row_top,int row_bot,int n) //max column-consecutive sum of an array
{
    int tmp[101]={0},i,j,maxi=-2147482648,sum=0;
    for(i=row_top;i<=row_bot;i++)//run thru most top row ~ most bottom row
    for(j=0;j<n;j++)//run thru all column and add them up
        tmp[j]+=ary[i][j];
    for(i=0;i<n;i++)
    {
        sum+=tmp[i];
        if(sum<0)
            sum=0;
        else if(sum>maxi)
            maxi=sum;
    }
    return maxi;
}
int main()
{
    int ary[101][101],n,i,j,max_sum=0,sum;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%d",&ary[i][j]);
        for(i=0;i<n;i++)
        for(j=i;j<n;j++)
        {
            sum=max_con_sum(ary,i,j,n);
            if(sum>max_sum)
                max_sum=sum;
        }
        printf("%d\n",max_sum);
    }
    return 0;
}
