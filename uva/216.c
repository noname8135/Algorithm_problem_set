#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
typedef struct COMPUTER
{
	int x,y;
}computer;
float dist(int x1,int x2,int y1,int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool next_per(int permutation[],int com_num) //0 = didn't move
{
    bool moved=0;
    int judge_to,tmp,now,i,j,k;

    for(judge_to=com_num-2;judge_to>=0;judge_to--)
    {
        for(now=com_num-1;now>judge_to;now--)
            for(i=now-1;i>=judge_to;i--)
            if(permutation[now]>permutation[i])
            {
                tmp=permutation[now];
                permutation[now]=permutation[i];
                permutation[i]=tmp;
                for(j=i+1,k=com_num-1;j<k;j++,k--)
                {
                    tmp=permutation[j];
                    permutation[j]=permutation[k];
                    permutation[k]=tmp;
                }
                return 1;
            }
    }
    return 0;
}
float dis_of_a_per(computer com[],int permutation[],int com_num)
{
    int i;
    float total=0;
    for(i=0;i<com_num-1;i++)
        total+=16+dist(com[permutation[i]].x,com[permutation[i+1]].x,com[permutation[i]].y,com[permutation[i+1]].y);
    return total;
}
int main()
{
	computer com[20];
	int j,com_num,i,permutation[20],network_count=0,ans_per[20];
	float min_dis,pre_dis;
	while(scanf("%d",&com_num)&&com_num)
	{
		printf("**********************************************************\nNetwork #%d\n",++network_count);
		for(i=0;i<com_num;i++)
		{
			scanf("%d%d",&(com[i].x),&(com[i].y));
			permutation[i]=i;
		}
		min_dis=5000;
		while(next_per(permutation,com_num))
		{
            if((pre_dis=dis_of_a_per(com,permutation,com_num))<min_dis)
            {
                min_dis=pre_dis;
                for(i=0;i<com_num;i++)
                    ans_per[i]=permutation[i];
            }
		}
		for(i=0;i<com_num-1;i++)
			{
				printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",com[ans_per[i]].x,com[ans_per[i]].y,com[ans_per[i+1]].x,com[ans_per[i+1]].y,16+dist(com[ans_per[i]].x,com[ans_per[i+1]].x,com[ans_per[i]].y,com[ans_per[i+1]].y));
			}
		printf("Number of feet of cable required is %.2f.\n",min_dis);
	}
	return 0;
}
