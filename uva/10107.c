#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a,const void* b)
{return *((int*)a)-*((int*)b);}
int main()
{
    int i,a[10001];
    i=0;
    while(scanf("%d",&a[i])!=EOF)
    {
    i++;
    qsort(a,i,sizeof(int),cmp);
    if(i%2)
    printf("%d\n",a[i/2]);
    else
    printf("%d\n",(a[i/2]+a[i/2-1])/2);
    }
    return 0;
}
