#include <stdio.h>
#include <math.h>
#include <float.h>
int main()
{
    double n, p, k;
    while(scanf("%lf %lf",&n,&p)!=EOF)
    printf("%.0lf\n",pow(p,1/n));
    return 0;
}
