#include <stdio.h>
#include <math.h>
int main()
{
    double B,H,S,collect_dia,r;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        collect_dia=0;
        scanf("%lf%lf",&B,&H);
        S=sqrt((B*B/4)+H*H);
        while(1)
        {
            r=B*H/(2*S+B);
            if(r<0.000001)
            break;
            collect_dia+=2*r;
            S*=(H-2*r)/H;
            B*=(H-2*r)/H;
            H-=2*r;
        }
        printf("%13.6lf\n",M_PI*collect_dia);
        if(n)
        printf("\n");
    }
    return 0;
}
