#include <stdio.h>
#include <stdlib.h>
typedef struct fsfsw
{
    int left,right;
}SET;
int cmp(const void* a,const void* b)
{
    return ((SET*)a)->left-((SET*)b)->left;
}

int main()
{
    SET set[100000],ans[100000];
    int t,M,counter,now,ans_count,max_index,max,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&M);
        counter=0,now=0;
        while(scanf("%d%d",&(set[counter].left),&(set[counter].right)))
        {
            if(set[counter].left==0&&set[counter].right==0)
                break;
            counter++;
        }
        ans_count=0;
        while(now<M)
        {
            max=0,max_index=-1;
            for(i=0;i<counter;i++)
            if(set[i].left<=now&&set[i].right>max)
            {
                max=set[i].right;
                max_index=i;
            }
            if(max_index==-1)
            break;
            now=max,ans[ans_count++]=set[max_index];
        }
        if(max_index==-1)
            printf("0\n");
        else
        {
            printf("%d\n",ans_count);
            qsort(ans,ans_count,sizeof(ans[0]),cmp);
            for(i=0;i<ans_count;i++)
                printf("%d %d\n",ans[i].left,ans[i].right);
        }
        if(t)
            printf("\n");
    }
    return 0;
}
