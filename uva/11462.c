#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a,const void* b)
{
    return *((int*)a)-*((int*)b);
}
int main()
{
    int n,i,*age;
    age=(int*)malloc(sizeof(int)*2000001);
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)
            scanf("%d",age+i);
        qsort(age,n,sizeof(int),cmp);
        for(i=0;i<n;i++)
            if(i!=n-1)
            printf("%d ",age[i]);
            else
            printf("%d\n",age[i]);
    }
    return 0;
}
