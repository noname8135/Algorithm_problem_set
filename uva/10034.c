#include <stdio.h>
#include <stdbool.h>
#include <math.h>
typedef struct fdss
{
   double x,y;
}DOT;

double dis(DOT a,DOT b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    bool visited[200];
    int i,t,n,min_index,j,set[200],counter;
    DOT dot[200];
    dot[0].x=1,dot[0].y=1,dot[1].x=2,dot[1].y=2;
    double min_dis,total;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {visited[i]=0;scanf("%lf %lf",&dot[i].x,&dot[i].y);}
        counter=1;
        set[0]=0;
        total=0.0;
        while(counter<n)
        {
            min_dis=9999999,min_index=-1;
            for(i=0;i<counter;i++)
            {
                for(j=1;j<n;j++)
                if(!visited[j]&&(min_index==-1||dis(dot[set[i]],dot[j])<min_dis))
                {
                    min_dis=dis(dot[set[i]],dot[j]);
                    min_index=j;
                }
            }
            total+=min_dis,set[counter++]=min_index,visited[min_index]=1;
        }
        printf("%.2lf\n",total);
        if(t)
            printf("\n");
    }
    return 0;
}
