#include <stdio.h>
int main()
{
    int day_count;
    double H,U,D,F,progress;
    while(scanf("%lf %lf %lf %lf",&H,&U,&D,&F))
    {
    if(!H)
    return 0;
    F=U*F/100;
    progress=0;day_count=1;
    while(1)
    {
        //printf("day%d ",day_count);
        //printf("goal = %lf, before p = %lf ",H,progress);
        if(U>0)
        progress+=U;
        //printf("after p = %lf ",progress);
        if(progress>H)
        {printf("success on day %d\n",day_count);break;}
        progress-=D;
        //printf("slided p = %lf\n",progress);
        if(progress<0)
        {printf("failure on day %d\n",day_count);break;}
        U-=F;
        day_count++;
    }
    }
}
