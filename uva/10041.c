#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a,const void* b)
{return*((int*)a)-*((int*)b);}

int main()
{
    int i,n,r,street_num[501],house,total_dis;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&r);
        for(i=0;i<r;i++)
        scanf("%d",&street_num[i]);
        qsort(street_num,r,sizeof(int),cmp);
        house=street_num[r/2];
        for(i=0,total_dis=0;i<r;i++)
        total_dis+=((house-street_num[i])>0?house-street_num[i]:street_num[i]-house);
        printf("%d\n",total_dis);
    }
    return 0;
}
