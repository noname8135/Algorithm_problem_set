#include <stdio.h>
#include <stdlib.h>

int cmp(char a,char b)
{
    if((a=='R'&&b=='S')||(a=='P'&&b=='R')||(a=='S'&&b=='P'))
    return 1;
    return 0;
}
int main()
{
    char **map,**tmp;
    map=(char**)malloc(sizeof(char*)*101);
    tmp=(char**)malloc(sizeof(char*)*101);
    int row,col,day,n,i,j,flag=0;
    for(i=0;i<100;i++)
    {map[i]=(char*)malloc(sizeof(char)*101);
    tmp[i]=(char*)malloc(sizeof(char)*101);}
    scanf("%d",&n);
    while(n--)
    {
        if(flag)
        printf("\n");
        else
        flag=1;
        scanf("%d%d%d\n",&row,&col,&day);
        for(i=0;i<row;i++)
        {for(j=0;j<col;j++)
        scanf("%c",&map[i][j]);
        scanf("\n");}
        while(day--)
        {
            tmp=(char**)malloc(sizeof(char*)*101);
            for(i=0;i<100;i++)
            tmp[i]=(char*)malloc(sizeof(char)*101);
            for(i=0;i<row;i++)
            {for(j=0;j<col;j++)
            tmp[i][j]=map[i][j];}
            for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                {
                    if(i-1>=0&&cmp(map[i][j],map[i-1][j]))
                    tmp[i-1][j]=map[i][j];//printf("i=%d j=%d hit i-1\n",i,j);}
                    if(i+1<row&&cmp(map[i][j],map[i+1][j]))
                    tmp[i+1][j]=map[i][j];//printf("i=%d j=%d hit i+1\n",i,j);}
                    if(j-1>=0&&cmp(map[i][j],map[i][j-1]))
                    tmp[i][j-1]=map[i][j];//printf("i=%d j=%d hit j-1\n",i,j);}
                    if(j+1<col&&cmp(map[i][j],map[i][j+1]))
                    tmp[i][j+1]=map[i][j];//printf("i=%d j=%d hit j+1\n",i,j);}
                }
            }
            map=tmp;
        }
        for(i=0;i<row;i++)
        {for(j=0;j<col;j++)
        printf("%c",map[i][j]);
        printf("\n");}
    }
    return 0;
}
