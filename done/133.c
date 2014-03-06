#include <stdio.h>

int main ()
{
	int position1,position2,people_num,clock_count,counter_count,out1,out2,line[50],i,kill_left,kill_right;
	while(scanf("%d%d%d",&people_num,&clock_count,&counter_count)&&people_num&&clock_count&&counter_count)
	{
		for(i=1;i<=people_num;i++)
			line[i]=i;
		position1=0;position2=people_num+1;
		while(people_num)
		{
			out1=(position1+clock_count-1)%people_num+1;
			out2=(position2-counter_count);
			if(out2<=0)
				out2=out2%people_num+people_num;
			if(out1==out2)
				{
					printf("%3d",line[out1]);
					for(i=out1;i<people_num;i++)
					line[i]=line[i+1];
					people_num--;
				}
			else
				{
					printf("%3d%3d",line[out1],line[out2]);
					kill_left=out1>out2?out2:out1;
					kill_right=out1>out2?out1:out2;
					for(i=kill_right;i<people_num;i++)
					line[i]=line[i+1];
					people_num--;
					for(i=kill_left;i<people_num;i++)
					line[i]=line[i+1];
					people_num--;
					if(out1>out2)
						out1--;
					else
						out2--;
				}
			if(people_num)
				printf(",");
			else
				printf("\n");
			position1=out1-1;
			position2=out2;
		}
	}
	return 0;
}