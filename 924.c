#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct fgegr
{
    int day,point;
}NODE;


int main()
{
    bool visited[3000];
    NODE node[3000];
    int T,E,**emp,start,i,j,max_day,max,spread,head,tail,DAY[3000];
    emp=(int**)malloc(sizeof(int*)*2600);
    for(i=0;i<2600;i++)
        emp[i]=(int*)malloc(sizeof(int)*2600);
    while(scanf("%d",&E)!=EOF)
    {
        for(i=0;i<E;i++)
        {
            scanf("%d",&emp[i][0]);
            for(j=1;j<=emp[i][0];j++)
            scanf("%d",&emp[i][j]);
        }
        scanf("%d",&T);
        while(T--)
        {
            for(i=0;i<E;i++)
            {
                visited[i]=0;
                DAY[i]=0;
            }
            scanf("%d",&start);
            node[0].point=start;
            node[0].day=0;
            head=0;tail=1;spread=0;
            visited[node[head].point]=1;
            while(head!=tail)
            {
                for(i=1;i<=emp[node[head].point][0];i++)
                {
                    if(!visited[emp[node[head].point][i]])
                    {
                        DAY[node[head].day]++;
                        node[tail].day=node[head].day+1;
                        node[tail++].point=emp[node[head].point][i];
                        visited[emp[node[head].point][i]]=1;
                    }
                }
                visited[node[head++].point]=1;
            }
            max=0;
            for(i=0;i<E;i++)
            {
                if(DAY[i]>max)
                {
                    max_day=i;
                    max=DAY[i];
                }
            }
            printf("%d",max);
            if(max)
            printf(" %d",max_day+1);
            printf("\n");
        }
    }
    return 0;
}
