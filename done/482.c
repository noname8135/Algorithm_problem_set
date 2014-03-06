#include <stdio.h>

int main()
{
    char ary[2000][20],junk;
    int i,n,index[2000],tmp,index_count;
    scanf("%d",&n);
    while(n--)
    {
        index_count=0;
        while(scanf("%d%c",&tmp,&junk))
        {
            index[index_count++]=tmp;
            if(junk=='\n')
                break;
        }
        for(i=0;i<index_count;i++)
        {
            scanf("%s",ary[index[i]-1]);
        }
        for(i=0;i<index_count;i++)
            printf("%s\n",ary[i]);
        if(n)
            printf("\n");
    }
    return 0;
}
