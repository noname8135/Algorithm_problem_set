#include <stdio.h>
#include <stdbool.h>
bool if_parity(bool ary[][100],int n)
{
    int i,j,sum;

    for(i=0;i<n;i++)
    {
        for(j=0,sum=0;j<n;j++)
        sum+=ary[i][j];
        if(sum%2)
            return 0;
    }

    for(i=0;i<n;i++)
    {
        for(j=0,sum=0;j<n;j++)
        sum+=ary[j][i];
        if(sum%2)
            return 0;
    }
    return 1;
}
bool if_fixable(bool ary[][100],int n)
{
    int i,j,sum,bad_row,bad_col,bad_row_count=0,bad_col_count=0;
    for(i=0;i<n;i++)
    {
        for(j=0,sum=0;j<n;j++)
        sum+=ary[i][j];
        if(sum%2)
        {bad_row_count++;bad_row=i;}
    }
    for(i=0;i<n;i++)
    {
        for(j=0,sum=0;j<n;j++)
        sum+=ary[j][i];
        if(sum%2)
        {bad_col_count++;bad_col=i;}
    }
    if(bad_row_count==1&&bad_col_count==1)
        {printf("Change bit (%d,%d)\n",bad_row+1,bad_col+1);return 1;}
    else
        return 0;
}
int main()
{
    bool ary[100][100]={0};
    int n,i,j;
    while(scanf("%d",&n))
    {
        if(!n)
        return 0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            scanf("%d",&ary[i][j]);
        if(if_parity(ary,n))
            printf("OK\n");
        else if(!if_fixable(ary,n))
            printf("Corrupt\n");
    }
}
