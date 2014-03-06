#include <stdio.h>
#include <math.h>

double cal(double p,double q,double r,double s,double t,double u,double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
int main()
{
    double high,low,med;
    double p,q,r,s,t,u;
    int first=1;
    while(scanf("%lf%lf%lf%lf%lf%lf",&p,&q,&r,&s,&t,&u)==6)
    {
        high=1.0000;
        low=0.0000;
        if(cal(p,q,r,s,t,u,high)*cal(p,q,r,s,t,u,low)>0)
            printf("No solution\n");
        else
        {
            while(high-low>0.000000001)
            {
                med=(high+low)/2;
                if(cal(p,q,r,s,t,u,high)==0)
                {
                    med=high;
                    break;
                }
                else if(cal(p,q,r,s,t,u,low)==0)
                {
                    med=low;
                    break;
                }
                else if(cal(p,q,r,s,t,u,high)*cal(p,q,r,s,t,u,med)<0)
                low=med;
                else
                high=med;
            }
            printf("%0.4lf\n",med);
        }
    }
    return 0;
}
