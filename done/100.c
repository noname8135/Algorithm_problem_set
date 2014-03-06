#include <stdio.h>
int count_step(int n)
{
    int count=1;
    while(n!=1)
    {
        if(n%2)
        n=n*3+1;
        else
        n/=2;
        count++;
    }
    return count;
}
int main()
{
    int i,j,tmp,max_step;
    while(scanf("%d %d",&i,&j)!=EOF)
    {
        max_step=0;
        printf("%d %d ",i,j);
        if(j<i)
        {
            tmp=i;
            i=j;
            j=tmp;
        }
        while(i<=j)
        {
            tmp=count_step(i);
            if(tmp>max_step)
            max_step=tmp;
            i++;
        }
        printf("%d\n",max_step);
    }
    return 0;
}
