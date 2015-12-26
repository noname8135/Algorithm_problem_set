#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool judge(char grid[][120],char keyword[],int start_x,int start_y)
{
    int i,dir_x,dir_y,pre_x,pre_y,kw_count;
    for(dir_x=-1;dir_x<2;dir_x++)
    {
        for(dir_y=-1;dir_y<2;dir_y++)
        {
            pre_x=start_x;pre_y=start_y;kw_count=0;
            while(keyword[kw_count]==grid[pre_x][pre_y])
            {
                if(keyword[++kw_count]=='\0')
                return 1;
                pre_x+=dir_x;pre_y+=dir_y;
            }
        }
    }
    return 0;
}
void turn_upr(char a[])
{
    int i;
    for(i=0;a[i]!='\0';i++)
    if(a[i]>='a'&&a[i]<='z')
    a[i]-=' ';
    return;
}
int main()
{
    int j,n,line_num,word_num,i,keyword_num;
    char grid[500][120],keyword[40];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&line_num,&word_num);
        for(i=0;i<line_num;i++)
        {scanf("%s",grid[i]);
        turn_upr(grid[i]);}
        scanf("%d",&keyword_num);
        label1:
        while(keyword_num--)
        {
            scanf("%s",keyword);
            turn_upr(keyword);
            for(i=0;i<line_num;i++)
            for(j=0;j<word_num;j++)
            if(grid[i][j]==keyword[0]&&judge(grid,keyword,i,j))
            {printf("%d %d\n",i+1,j+1);goto label1;}
        }
        if(n)
        printf("\n");
    }
    return 0;
}
