#include <stdio.h>

int main()
{
    int lb,smaller,max,i,n,j,ary[10001],rank_inc[10001],rank_dec[10001],tmp[10001],rank_num;

    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&ary[i]);
        rank_num=1;
        tmp[0]=ary[0];
        rank_inc[0]=0;
        for(i=1;i<n;i++)    //find lis
            {
                for(j=0;j<rank_num;j++)
                if(ary[i]<=tmp[j])
                {
                    tmp[j]=ary[i];
                    rank_inc[i]=j;
                    break;
                }
                if(j==rank_num)
                {
                    rank_inc[i]=rank_num;
                    tmp[rank_num++]=ary[i];
                }
            }
        rank_num=1;
        tmp[0]=ary[n-1];
        rank_dec[n-1]=0;
        for(i=n-2;i>=0;i--) //find lds
            {
                for(j=0;j<rank_num;j++)
                if(ary[i]<=tmp[j])
                {
                    tmp[j]=ary[i];
                    rank_dec[i]=j;
                    break;
                }
                if(j==rank_num)
                {
                    rank_dec[i]=rank_num;
                    tmp[rank_num++]=ary[i];
                }
            }
        max=0;
        for(i=0;i<n;i++)
            {
                lb=rank_inc[i]>rank_dec[i]?rank_dec[i]+1:rank_inc[i]+1;
                if(max<lb*2-1)
                    max=lb*2-1;
            }
            printf("%d\n",max);

    }
    return 0;
}
