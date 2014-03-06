#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Team_record
{
    char name[51];
    int point,win,tie,lose,game,score,against,diff;
}
TEAM;
int mycmp(char a[],char b[])
{
    int i=0;
    while(1)
    {
        if(a[i]>='A'&&a[i]<='Z'&&b[i]>='a'&&b[i]<='z'&&a[i]+' '!=b[i])
        return a[i]-b[i]+' ';
        else if(a[i]>='a'&&a[i]<='z'&&b[i]>='A'&&b[i]<='Z'&&a[i]-' '!=b[i])
        return a[i]-b[i]-' ';
        else if(a[i]!=b[i])
        return a[i]-b[i];
        else if(a[i]=='\0'&&b[i]=='\0')
        return 0;
        i++;
    }
}
int cmp(const void* a,const void* b)
{
    TEAM a_team=*((TEAM*)a),b_team=*((TEAM*)b);
    if(a_team.point-b_team.point!=0)
    return -(a_team.point-b_team.point);
    if(a_team.win-b_team.win!=0)
    return -(a_team.win-b_team.win);
    if(a_team.diff-b_team.diff!=0)
    return -(a_team.diff-b_team.diff);
    if(a_team.score-b_team.score!=0)
    return -(a_team.score-b_team.score);
    if(a_team.game-b_team.game!=0)
    return (a_team.game-b_team.game);
    return mycmp(a_team.name,b_team.name);
}
int main()
{
    int k,j,i,n,team_num,stat_num,score_temp[2];
    TEAM *team;
    char tournament[200],temp[100],team_temp[2][51];
    scanf("%d\n",&n);
    while(n--)
    {
        fgets(tournament,199,stdin);
        printf("%s",tournament);
        scanf("%d\n",&team_num);
        team=(TEAM*)malloc(sizeof(TEAM)*team_num+1);
        for(i=0;i<team_num;i++)
        {
            team[i].point=0;
            team[i].win=0;
            team[i].tie=0;
            team[i].lose=0;
            team[i].game=0;
            team[i].score=0;
            team[i].against=0;
            team[i].diff=0;
        }
        for(i=0;i<team_num;i++)
        {fgets(team[i].name,50,stdin); team[i].name[strlen(team[i].name)-1]='\0';}
        scanf("%d\n",&stat_num);
        for(i=0;i<stat_num;i++)
        {
            fgets(temp,100,stdin);
            for(j=0;temp[j]!='\0';j++)
            if(temp[j]==' ')
            temp[j]='#';
            else if(temp[j]=='#'||temp[j]=='@')
            temp[j]=' ';
            sscanf(temp,"%s%d%d%s",team_temp[0],&score_temp[0],&score_temp[1],team_temp[1]);
            for(j=0;team_temp[0][j]!='\0';j++)
            if(team_temp[0][j]=='#')
            team_temp[0][j]=' ';
            for(j=0;team_temp[1][j]!='\0';j++)
            if(team_temp[1][j]=='#')
            team_temp[1][j]=' ';
            j=0;k=0;
            while(strcmp(team[j].name,team_temp[0]))
            j++;
            while(strcmp(team[k].name,team_temp[1]))
            k++;
            team[j].game++;team[k].game++;
            team[j].score+=score_temp[0];team[k].score+=score_temp[1];
            team[j].against+=score_temp[1];team[k].against+=score_temp[0];
            if(score_temp[0]>score_temp[1])
            {
                team[j].win++;team[k].lose++;
            }
            else if(score_temp[0]<score_temp[1])
            {
                team[j].lose++;team[k].win++;
            }
            else
            {
                team[j].tie++;team[k].tie++;
            }
        }
        for(i=0;i<team_num;i++)
        {
            team[i].point=3*team[i].win+team[i].tie;
            team[i].diff=team[i].score-team[i].against;
        }
        qsort(team,team_num,sizeof(TEAM),cmp);
        for(i=0;i<team_num;i++)
        printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,team[i].name,team[i].point,team[i].game,team[i].win,team[i].tie,team[i].lose,team[i].diff,team[i].score,team[i].against);
        scanf("\n");
        if(n)
        printf("\n");
        free(team);
    }
    return 0;
}
