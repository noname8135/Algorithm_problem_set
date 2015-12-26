#include <stdio.h>

int main()
{
    int num;
    while(scanf("%d",&num))
    {
        if(!num)
        return 0;
        else if(num>100)
        printf("f91(%d) = %d\n",num,num-10);
        else
        printf("f91(%d) = 91\n",num);
    }
}
