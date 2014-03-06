#include <stdio.h>
#include <string.h>

int main()
{
    int i,n,count_X[20],max,space,counter;
    char temp;
    while(scanf("%d\n",&n))
    {
        if(n==0)
        return 0;
        max=0;space=0;i=n;
        memset(count_X,0,sizeof(count_X));
        while(i--)
        {
            counter=25;
            while(counter--)
        {
            scanf("%c",&temp);
            if(temp=='X')
            count_X[i]++;
        }
        scanf("\n");
        }
        for(i=0;i<n;i++)
        if(max<count_X[i])
        max=count_X[i];
        for(i=0;i<n;i++)
        space+=max-count_X[i];
        printf("%d\n",space);
    }
}
