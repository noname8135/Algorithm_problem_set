#include <stdio.h>
#include <stdbool.h>
int max,value[8][8];
bool cant[8][8];
void find(int row,int pos,int sum)
{
    int i,ori[8][8],j,k;
    sum+=value[row][pos];
    for(i=row+1;i<8;i++)
    cant[i][pos]=1;
    for(i=1;pos+i<8&&row+i<8;i++)
    cant[row+i][pos+i]=1;
    for(i=0;pos-i>=0&&row+i<8;i++)
    cant[row+i][pos-i]=1;
    if(row<7)
    {
        for(i=0;i<8;i++)
        if(cant[row+1][i]==0)
        {
            for(j=row;j<8;j++)
            for(k=0;k<8;k++)
            ori[j][k]=cant[j][k];
            find(row+1,i,sum);
            for(j=row;j<8;j++)
            for(k=0;k<8;k++)
            cant[j][k]=ori[j][k];
        }
    }
    else
    {
        if(sum>max)
        max=sum;
        return ;
    }
}
int main()
{
    int i,j,t,k;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<8;i++)
        for(j=0;j<8;j++)
        scanf("%d",&value[i][j]);
        max=0;
        for(i=0;i<8;i++)
        {
            for(j=0;j<8;j++)
            for(k=0;k<8;k++)
            cant[j][k]=0;
            find(0,i,0);
        }
        printf("%5d\n",max);
    }
    return 0;
}
