#include <stdio.h>

int main()
{
    int num,tmp,next_num;
    while(scanf("%d",&num)&&num)
    {
        while(num>=10)
        {
            tmp=num;next_num=0;
            while(tmp)
            {
                next_num+=tmp%10;
                tmp/=10;
            }
            num=next_num;
        }
        printf("%d\n",num);
    }
    return 0;
}
