#include <stdio.h>
int m,n;
char oil[101][101];
void dfs(int i,int j)
{
    if(i<0||i>=m||j<0||j>=n||oil[i][j]=='*')
        return;
    oil[i][j]='*';
    dfs(i+1,j);dfs(i+1,j-1);dfs(i+1,j+1);
    dfs(i,j+1);dfs(i,j-1);
    dfs(i-1,j);dfs(i-1,j+1);dfs(i-1,j-1);
    return;
}
int main()
{
    int i,j,counter;
    while(scanf("%d %d\n",&m,&n)&&m)
    {
        counter=0;
        for(i=0;i<m;i++)
            {for(j=0;j<n;j++)
            scanf("%c",&oil[i][j]);scanf("\n");}
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            if(oil[i][j]=='@')
                {
                    counter++;
                    dfs(i,j);
                }

        printf("%d\n",counter);
    }
    return 0;
}
