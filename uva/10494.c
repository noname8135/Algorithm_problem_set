#include <stdio.h>
int main()
{
    char dividend[10000],sign[2];
    long long int temp,divisor;
    int i,first_flag;
    while(scanf("%s %s %lld",dividend,sign,&divisor)==3)
    {
        if(sign[0]=='/')
        {
            for(i=0,temp=0,first_flag=0;dividend[i]!='\0';i++,temp*=10)
            {
                temp+=(dividend[i]-'0');
                if(!first_flag&&temp/divisor)
                first_flag=1;
                if(first_flag)
                printf("%lld",temp/divisor);
                temp%=divisor;
            }
            if(!first_flag)
            printf("0");
            printf("\n");
        }
        else
        {
            for(i=0,temp=0;dividend[i]!='\0';i++)
            {
                temp*=10;
                temp+=(dividend[i]-'0');
                temp%=divisor;
            }
            printf("%lld\n",temp);
        }
    }
    return 0;
}
