#include <stdio.h>
#include <limits.h>
int cut_position[51],cost_ary[51][51];
int min(int left,int right)
{
    int i,now_cost=1000000,cost;
    if(cost_ary[left][right]!=-1)
        return cost_ary[left][right];
    else if(left+1==right-1)
    {
        cost_ary[left][right]=cut_position[right]-cut_position[left];
        return cut_position[right]-cut_position[left];
    }
    else if(left==right-1)
    {
        cost_ary[left][right]=0;
        return 0;
    }
    for(i=left+1;i<=right-1;i++)
        {
            cost=min(left,i)+min(i,right);
            if((cost)<now_cost)
            {
                now_cost=cost;
            }
        }
        now_cost+=cut_position[right]-cut_position[left];
    cost_ary[left][right]=now_cost;
    return now_cost;
}
int main()
{
    int i,j,cut_time,length;
    while(scanf("%d",&length)&&length!=0)
    {
        scanf("%d",&cut_time);
        cut_position[0]=0;cut_position[cut_time+1]=length;
        for(i=0;i<=cut_time;i++)
            for(j=i+1;j<=cut_time+1;j++)
            cost_ary[i][j]=-1;
        for(i=1;i<=cut_time;i++)
        scanf("%d",&cut_position[i]);
        printf("The minimum cutting is %d.\n",min(0,cut_time+1));
    }
}
