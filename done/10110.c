#include <stdio.h>
#include <math.h>
int factor(unsigned int num)
{
    int temp=(int)sqrt(num);
    return temp*temp==num?1:0;
}
int main()
{
    int n,i;
    while(scanf("%d",&n)&&n)
    if(n==1)
    printf("yes\n");
    else
    printf("%s\n",(factor(n)%2)?"yes":"no");
}
