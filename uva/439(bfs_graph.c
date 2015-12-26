#include <stdio.h>
#include <string.h>
#include <stdbool.h>
typedef struct STATE
{
    int x,y,step;
}State;

void push_Q(State Queue[],int* q_count,int in_x,int in_y,int in_step,bool visited[][8])
{
    if(in_x>=8||in_x<0||in_y<0||in_y>=8||visited[in_x][in_y])
        return ;
    Queue[*q_count].x=in_x;
    Queue[*q_count].y=in_y;
    Queue[(*q_count)++].step=in_step;
    return ;
}
State pop_Q(State Queue[],int* q_count)
{
    State item;
    item.x=Queue[0].x;
    item.y=Queue[0].y;
    item.step=Queue[0].step;
    int i;
    for(i=0;i<(*q_count)-1;i++)
    Queue[i]=Queue[i+1];
    (*q_count)--;
    return item;
}

int BFS(State Queue[],int* q_count,int des_x,int des_y,bool visited[][8])
{
    State walker;
    walker=pop_Q(Queue,q_count);
    visited[walker.x][walker.y]=1;
    if(walker.x==des_x&&walker.y==des_y)
    return walker.step;
    push_Q(Queue,q_count,walker.x-1,walker.y+2,walker.step+1,visited);
    push_Q(Queue,q_count,walker.x-1,walker.y-2,walker.step+1,visited);
    push_Q(Queue,q_count,walker.x+1,walker.y+2,walker.step+1,visited);
    push_Q(Queue,q_count,walker.x+1,walker.y-2,walker.step+1,visited);
    push_Q(Queue,q_count,walker.x-2,walker.y+1,walker.step+1,visited);
    push_Q(Queue,q_count,walker.x-2,walker.y-1,walker.step+1,visited);
    push_Q(Queue,q_count,walker.x+2,walker.y+1,walker.step+1,visited);
    push_Q(Queue,q_count,walker.x+2,walker.y-1,walker.step+1,visited);
    return BFS(Queue,q_count,des_x,des_y,visited);
}
int main()
{
    int from_x,from_y,to_x,to_y,q_count;
    char from_str[3],to_str[3];
    bool visited[8][8];
    State state[500];
    while(scanf("%s %s",from_str,to_str)==2)
    {
        q_count=0;
        memset(visited,0,sizeof(bool)*64);
        from_x=from_str[0]-'a';
        from_y=from_str[1]-'1';
        to_x=to_str[0]-'a';
        to_y=to_str[1]-'1';
        push_Q(state,&q_count,from_x,from_y,0,visited);
        printf("To get from %s to %s takes %d knight moves.\n",from_str,to_str,BFS(state,&q_count,to_x,to_y,visited));
    }
    return 0;
}
