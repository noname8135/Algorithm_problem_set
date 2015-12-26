#include <stdio.h>
#include <stdbool.h>

int t,ary[20],n,found,now_in[20],last_counter[500],last_in[500][20],last_ele_num;
void recur(int sum,int cur,int counter)
{
    if(sum==t)
    {
        int i,j;
        for(i=0;i<last_ele_num;i++)
        {
            if(counter==last_counter[i])
            {
                for(j=0;j<last_counter[i];j++)
                if(last_in[i][j]!=now_in[j])
                break;
                if(j==last_counter[i])
                return;
            }
        }
        last_counter[last_ele_num]=counter;
        for(i=0;i<counter-1;i++)
        {printf("%d+",now_in[i]);last_in[last_ele_num][i]=now_in[i];}
        printf("%d\n",now_in[i]);last_in[last_ele_num][i]=now_in[i];
        last_ele_num++;
        found=1;
        return ;
    }
    else if(cur==n||sum>t)
    return ;
    now_in[counter]=ary[cur];
    recur(sum+ary[cur],cur+1,counter+1);
    recur(sum,cur+1,counter);
    return;
}
int cmp(const void* a,const void *b)
{
    return *((int*)b)-*((int*)a);
}
int main()
{
	int i;
	while(scanf("%d%d",&t,&n)&&(t||n))
	{
		printf("Sums of %d:\n",t);
		for(i=0;i<n;i++)
        scanf("%d",ary+i);
        found=0;last_ele_num=0;

        recur(0,0,0);
		if(!found)
			printf("NONE\n");
	}
	return 0;
}
