#include <stdio.h>
void mul(int total[],int num)
{
    int i;
    for(i=0;i<999;i++)
        total[i]*=num;
    for(i=0;i<999;i++)
        if(total[i]>=10)
        {
            total[i+1]+=total[i]/10;
            total[i]%=10;
        }
    return ;
}
void add(int total[],int num[])
{
    int i;
    for(i=0;i<999;i++)
        {
            total[i]+=num[i];
            if(total[i]>=10)
            {
                total[i+1]++;
                total[i]-=10;
            }
        }
    return ;
}
int main()
{
    int total[1000],multi[1000],tmp[1000];
    int N,A,i,j;
    while(scanf("%d%d",&N,&A)==2)
    {
        for(i=0;i<1000;i++)
        {total[i]=0;multi[i]=0;}
        multi[0]=1;
        for(i=1;i<=N;i++)
        {
            mul(multi,A);
            for(j=0;j<1000;j++)
                tmp[j]=multi[j];
            mul(tmp,i);
            add(total,tmp);
        }
        for(i=999;total[i]==0&&i>0;i--)
            ;
        for(;i>=0;i--)
        printf("%d",total[i]);
        printf("\n");
    }
    return 0;
}
