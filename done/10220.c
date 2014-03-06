#include <stdio.h>
#include <stdlib.h>
int main()
{
    int counter,num,**a;
    a=(int**)malloc(sizeof(int*)*1001);
    int i,j;
    for(i=0;i<=1000;i++)
        {
            a[i]=(int*)malloc(sizeof(int)*(i/10+1)*(i+3));
            for(j=0;j<(i/10+1)*(i+3);j++)
            a[i][j]=0;
        }

    a[1][0]=1;

    for(i=1;i<1000;i++)
    {
        for(j=0;j<(i/10+1)*(i+3);j++)
        a[i+1][j]=a[i][j]*(i+1);
        for(j=0;j<(i/10+1)*(i+3);j++)
        if(a[i+1][j]>=10)
        {
            a[i+1][j+1]+=a[i+1][j]/10;
            a[i+1][j]%=10;
        }
    }
    /*for(i=1;i<=1000;i++)
    {
        for(j=0;j<(i/10+1)*(i+3);j++)
        printf("%d",a[i][j]);
        printf("\n");
    }*/
    while(scanf("%d",&num)!=EOF)
    {
        counter=0;
        for(i=0;i<(num/10+1)*(num+3);i++)
            counter+=a[num][i];
        printf("%d\n",counter);
    }
    return 0;
}
