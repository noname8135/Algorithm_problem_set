#include <stdio.h>
int main()
{
    int i,n,a[200],total,move,set_count=0;
    while(scanf("%d",&n))
    {
    if(!n)
    return 0;
    for(total=0,i=0;i<n;i++)
    {scanf("%d",&a[i]);total+=a[i];}
    for(i=0,move=0;i<n;i++)
    {if(a[i]<total/n)
    move+=total/n-a[i];
    }
    printf("Set #%d\nThe minimum number of moves is %d.\n",++set_count,move);
    printf("\n");
    }
}
