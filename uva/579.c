#include <stdio.h>

int main()
{
    float hour,minute,angle;
    while(scanf("%f:%f",&hour,&minute))
    {
        if(hour==0&&minute==0)
        return 0;
        hour=(hour+minute/60)*30;
        minute*=6;
        angle=minute-hour;
        if(angle<0)
        angle+=360;
        if(angle>180)
        angle=360-angle;
        printf("%.3f\n",angle);
    }
}
