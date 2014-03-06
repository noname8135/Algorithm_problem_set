#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
bool DFS(int **graph,int vertice,int color[])
{
    int i,new_color=(color[vertice]==1?2:1);
    for(i=1;i<=graph[vertice][0];i++)
    {
        if(!color[graph[vertice][i]])
        {
            color[graph[vertice][i]]=new_color;
            if(DFS(graph,graph[vertice][i],color))
            return 1;
        }
        else if(color[graph[vertice][i]]!=new_color)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int j,a,b,i,n,m,color[200],color_count,new_color;
    int **graph;
    while(scanf("%d",&n)&&n&&scanf("%d",&m))
    {
        graph=(int**)malloc(sizeof(int*)*n);
        for(i=0;i<n;i++)
            {
                graph[i]=(int*)malloc(sizeof(int)*(n+1));
                graph[i][0]=0;  //number of connected points
            }

        memset(color,0,sizeof(int)*n);  //0 = uncolored
        while(m--)
        {
            scanf("%d %d",&a,&b);
            graph[a][++graph[a][0]]=b;
            graph[b][++graph[b][0]]=a;
        }
        color[0]=1;
        if(DFS(graph,0,color))
        printf("NOT BICOLORABLE.\n");
        else
        printf("BICOLORABLE.\n");
        for(i=0;i<n;i++)
            free(graph[i]);
        free(graph);
    }
}
