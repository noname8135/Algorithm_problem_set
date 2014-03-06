#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return *((int*)a)-*((int*)b);
}
int main()
{
    int i,j,n,found;
    int* from,*to;
    from=(int*)malloc(sizeof(int)*500000);
    to=(int*)malloc(sizeof(int)*500000);
    while(scanf("%d",&n)&&n)
    {
        for(i=0;i<n;i++)
        scanf("%d%d",&from[i],&to[i]);
        qsort(from,i,sizeof(int),cmp);
        qsort(to,i,sizeof(int),cmp);

        for(j=0;j<i;j++)
        {
            if(to[j]!=from[j])
            break;
        }

        if(i!=j)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
