#include <stdio.h>
#include <stdbool.h>
typedef struct EVENT{
    bool on_off;
    int measure,id,beat,tick;
}Event;
void round_carry(Event event[],int event_count)
{
    int i,after_round;
    for(i=0;i<event_count;i++)
    {
        after_round=(event[i].tick)/60*60;
        event[i].tick=(event[i].tick-after_round<after_round+60-event[i].tick)?after_round:after_round+60;
        if(event[i].tick==480)
        {
            event[i].beat++;
            event[i].tick=0;
        }
        if(event[i].beat==5)
        {
            event[i].beat=1;
            event[i].measure++;
        }
    }
    return ;
}
int dismiss(Event event[],int event_count)
{
    int i,j,kill_count=0;
    for(i=0;i<event_count-1;i++)
    {
        for(j=i+1;j<event_count;j++)
        {
            if(event[i].id==event[j].id&&event[i].on_off==1&&event[j].on_off==0&&event[i].measure==event[j].measure&&event[i].beat==event[j].beat&&event[i].tick==event[j].tick)
            {
                event[i].id=-1;
                event[j].id=-1;
                kill_count+=2;
            }
        }
    }
    return kill_count;
}
int main()
{
    int event_count,i,kill_count;
    Event event[3001];
    while(scanf("%d",&event_count)&&event_count!=-1)
    {
        for(i=0;i<event_count;i++)
            scanf("%d %d %d %d %d\n",&(event[i].on_off),&(event[i].id),&(event[i].measure),&(event[i].beat),&(event[i].tick));
        round_carry(event,event_count);
        kill_count=dismiss(event,event_count);
        printf("%d",event_count-kill_count);
        for(i=0;i<event_count;i++)
            if(event[i].id!=-1)
        printf("\n%d %d %d %d %d",event[i].on_off,event[i].id,event[i].measure,event[i].beat,event[i].tick);
        printf("\n\n");
    }
    printf("-1");
    return 0;
}
