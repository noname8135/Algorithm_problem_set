#include <stdio.h>

int main()
{
    int max,min,n,tmp[3];
    scanf("%d",&n);
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("Case %d: ",i+1);
        max=0;min=10000;
        for(j=0;j<3;j++)
        {
            scanf("%d",&tmp[j]);
            if(tmp[j]>max)
                max=tmp[j];
            if(tmp[j]<min)
                min=tmp[j];
        }
        for(j=0;j<3;j++)
        if(tmp[j]!=max&&tmp[j]!=min)
        {
            printf("%d\n",tmp[j]);
            break;
        }
    }
    return 0;
}
