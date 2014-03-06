#include <stdio.h>
#include <string.h>
#include <stdbool.h>
typedef struct fgeoej
{
    int depth,point;
}QUEUE;
bool diff_one_char(char* a,char* b)
{
    int i;
    bool flag=0;
    if(strlen(a)!=strlen(b))
        return 0;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]!=b[i]&&flag)
            return 0;
        else if(a[i]!=b[i])
            flag=1;
    }
    return flag;
}
int main()
{
    char dic[300][20],start_str[20],goal_str[20],str[100];
    int T,counter,i,j,len;
    bool visited[300];
    QUEUE Q[301],walker;
    int connect[300][300],head,tail,start,goal;
    scanf("%d\n\n",&T);
    while(T--)
    {
        counter=0;
        while(fgets(dic[counter],19,stdin))
        {
            if(dic[counter][0]=='*')
            break;
            len=strlen(dic[counter]);
            dic[counter][len-1]='\0';
            connect[counter][0]=0;
            counter++;
        }
        for(i=0;i<counter-1;i++)
        for(j=i+1;j<counter;j++)
        if(diff_one_char(dic[i],dic[j]))
        {
            connect[i][connect[i][0]+1]=j;
            connect[j][connect[j][0]+1]=i;
            connect[i][0]++;
            connect[j][0]++;
        }
        while(fgets(str,99,stdin))
        {
            if(str[0]=='\n')
                break;
            sscanf(str,"%s",start_str);
            sscanf(str+strlen(start_str),"%s",goal_str);
            for(i=0;i<counter;i++)
            {
                if(!strcmp(start_str,dic[i]))
                    start=i;
                else if(!strcmp(goal_str,dic[i]))
                    goal=i;
            }
            for(i=0;i<counter;i++)
                visited[i]=0;
            head=0,tail=1;
            Q[0].depth=0,Q[0].point=start;
            visited[start]=1;
            while(1)
            {
                walker=Q[head++];
                if(!strcmp(dic[walker.point],goal_str))
                    break;

                for(i=1;i<=connect[walker.point][0];i++)
                {
                    if(!visited[connect[walker.point][i]])
                    {

                        Q[tail].depth=walker.depth+1;
                        Q[tail].point=connect[walker.point][i];
                        visited[connect[walker.point][i]]=1;
                        tail++;
                    }
                }
            }
            printf("%s %s %d\n",start_str,goal_str,walker.depth);
        }
        if(T)
        printf("\n");
    }
    return 0;
}
