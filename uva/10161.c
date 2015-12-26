#include <stdio.h>
#include <math.h>
int main()
{
    int step,num,sqrt_num,x,y;
    while(scanf("%d",&num)&&num)
    {
        sqrt_num=(int)sqrt(num);
        step=sqrt_num*sqrt_num;
        if(sqrt_num%2)
        {
            x=1;
            y=sqrt_num;
            if(step!=num)
            {
                step++;
                y++;
                if(step!=num&&num-step<=y-1)
                    x+=num-step;
                else if(step!=num)
                {
                    x=y;
                    step+=y-1;
                    y-=num-step;
                }
            }
        }
        else
        {
            x=sqrt_num;
            y=1;
            if(step!=num)
            {
                step++;
                x++;
                if(step!=num&&num-step<=x-1)
                    y+=num-step;
                else if(step!=num)
                {
                    y=x;
                    step+=x-1;
                    x-=num-step;
                }
            }
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}
