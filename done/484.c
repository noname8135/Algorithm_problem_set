#include <stdio.h>

int main()
{
    int num[10000],count[10000],num_count=0,tmp;
    int i;
    while(scanf("%d",&tmp)!=EOF)
    {
        for(i=0;i<num_count;i++)
            if(tmp==num[i])
                {
                    count[i]++;
                    break;
                }
        if(i==num_count)
            {
                num[num_count]=tmp;
                count[num_count++]=1;
            }
    }
    for(i=0;i<num_count;i++)
        printf("%d %d\n",num[i],count[i]);
    return 0;
}
