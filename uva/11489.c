#include <stdio.h>
#include <stdbool.h>
int main()
{
    bool Swin;
    int i,case_count=0,t,num[5000],dg_count,tot,temp,one_remain,remain,found;
    char tmp;
    scanf("%d\n",&t);
    while(t--)
    {
        dg_count=0,tot=0;
        while(scanf("%c",&tmp)==1&&tmp!='\n')
        {
            tot+=tmp-'0';
            num[dg_count++]=tmp-'0';
        }
        remain=tot%3,found=0;
        for(i=0;i<dg_count;i++)
        {
            //printf("num=%d\n",num[i]%3);
            if(num[i]%3==remain)
        {
            found=1;
            temp=num[i];
            num[i]=num[dg_count-1];
            num[--dg_count]=temp;
            break;
        }
        }
       // printf("remain=%d\n",remain);
        if(dg_count==0)
        {
            //printf("A");
            printf("Case %d: S\n",++case_count);
            continue;
        }
        else if(!found||dg_count==1)
        {
            //printf("B");
            printf("Case %d: T\n",++case_count);
            continue;
        }
        one_remain=0;
        for(i=0;i<dg_count;i++)
        {
            if(num[i]%3)
            one_remain++;
        }
        //printf("one remain=%d\n",one_remain);
        if(one_remain==1||one_remain==0)
        {
            if(dg_count%2==0)
            Swin=1;
            else
            Swin=0;
        }
        else
        {
            if((dg_count-one_remain)%2==0)
            Swin=1;
            else
            Swin=0;
        }
        if(Swin)
        printf("Case %d: S\n",++case_count);
        else
        printf("Case %d: T\n",++case_count);
    }
    return 0;
}
