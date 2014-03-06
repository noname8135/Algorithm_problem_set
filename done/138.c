#include <stdio.h>

int main()
{
    int count=1;
    long long int house=6,last=8,left=15,right=15;
    printf("%10d%10d\n",6,8);
    while(count<10)
    {
        last++;
        right+=last;
        while(left<right)
        {
            left+=house;
            right-=(house+1);
            house++;
        }
        if(left==right)
            {
                count++;
                printf("%10lld%10lld\n",house,last);
            }
    }
    return 0;
}
