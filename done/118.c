#include <stdio.h>
#include <stdbool.h>
void turn(char* face,char dir)
{
    if(*face=='N')
    {
        if(dir=='R')
            *face='E';
        else if(dir=='L')
            *face='W';
    }
    else if(*face=='S')
    {
        if(dir=='R')
            *face='W';
        else if(dir=='L')
            *face='E';
    }
    else if(*face=='E')
    {
        if(dir=='R')
            *face='S';
        else if(dir=='L')
            *face='N';
    }
    else if(*face=='W')
    {
        if(dir=='R')
            *face='N';
        else if(dir=='L')
            *face='S';
    }
    return ;
}
bool out(int x,int y,int border_x,int border_y)
{
    if(x<0||y<0||x>border_x||y>border_y)
        return 1;
    return 0;
}
void proceed(char instruction[],int* now_x,int* now_y,char* face,int border_x,int border_y,bool* lost,int scent_x[],int scent_y[],int* scent_count)
{
    int j,i,future_x,future_y,save;
    for(i=0;instruction[i]!='\0';i++)
    {
        if(instruction[i]=='F')
        {
            future_x=*now_x;
            future_y=*now_y;
            if(*face=='N')
            future_y++;
            else if(*face=='S')
            future_y--;
            else if(*face=='E')
            future_x++;
            else if(*face=='W')
            future_x--;
            if(out(future_x,future_y,border_x,border_y))
            {
                save=0;
                for(j=0;j<*scent_count;j++)
                {
                    if(*now_x==scent_x[j]&&*now_y==scent_y[j])
                    save=1;
                }
                if(save)
                    continue;
                *lost=1;
                scent_x[*scent_count]=*now_x;
                scent_y[*scent_count]=*now_y;
                (*scent_count)++;
                return ;
            }
            else
            {
                *now_x=future_x;
                *now_y=future_y;
            }
        }
        else
        turn(face,instruction[i]);
    }
    return ;
}
int main()
{
    bool lost;
    int border_x,border_y,now_x,now_y,scent_x[3000],scent_y[3000],scent_count=0;
    char face,instruction[200];
    scanf("%d%d",&border_x,&border_y);
    while(scanf("%d %d %c\n",&now_x,&now_y,&face)==3)
    {
        lost=0;
        fgets(instruction,150,stdin);
        proceed(instruction,&now_x,&now_y,&face,border_x,border_y,&lost,scent_x,scent_y,&scent_count);
        printf("%d %d %c",now_x,now_y,face);
        if(lost)
            printf(" LOST");
        printf("\n");
    }
    return 0;
}
