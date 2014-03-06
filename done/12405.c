#include <stdio.h>
#include <stdbool.h>

int main()
{
    char tmp;
    int t,n,i,cas=0,counter;
    bool situ[200];
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",++cas);
        scanf("%d\n",&n);
        for(i=0;i<n;i++)
        {
            scanf("%c",&tmp);
            if(tmp=='.')
            situ[i]=1;
            else if(tmp=='#')
            situ[i]=0;

        }
        counter=0;
        for(i=1;i<n+1;)
        {
            if(situ[i-1])
            {
                counter++;
                situ[i-1]=0,situ[i]=0,situ[i+1]=0;
                i+=3;
            }
            else
            i++;
        }
        printf("%d\n",counter);
    }
    return 0;
}
