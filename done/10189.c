#include <stdio.h>

int main()
{
    int m,n,i,j,mine_counter,field_count=0;
    char field[103][103];
    while(scanf("%d %d\n",&m,&n))
    {
        if(m==0&&n==0)
        return 0;
        if(field_count)
        printf("\n");
        printf("Field #%d:\n",++field_count);
        for(i=0;i<=m+1;i++)
        {
        for(j=0;j<=n+1;j++)
        if(i==0||j==0||i==m+1||j==n+1)
        field[i][j]='!';
        else
        {scanf("%c",&field[i][j]);
        scanf("\n");}
        }
        for(i=1;i<=m;i++)
        {
        for(j=1;(mine_counter=0)||j<=n;j++)
        {if(field[i][j]=='*')
        {printf("*");continue;}
        if(field[i+1][j]=='*')
        mine_counter++;
        if(field[i][j-1]=='*')
        mine_counter++;
        if(field[i][j+1]=='*')
        mine_counter++;
        if(field[i-1][j+1]=='*')
        mine_counter++;
        if(field[i-1][j-1]=='*')
        mine_counter++;
        if(field[i-1][j]=='*')
        mine_counter++;
        if(field[i+1][j-1]=='*')
        mine_counter++;
        if(field[i+1][j+1]=='*')
        mine_counter++;
        printf("%d",mine_counter);}
        printf("\n");
        }
    }
}
