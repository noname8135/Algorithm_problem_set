#include <stdio.h>
int main()
{
    int n,i,A_count,B_count,game_count=0,j,ans[1000],guess[1000],tmp[1000];
    while(scanf("%d",&n))
    {
    if(!n)
    return 0;
    printf("Game %d:\n",++game_count);
    for(i=0;i<n;i++)
    scanf("%d",&ans[i]);
    while(1)
    {
        for(i=0;i<n;i++)
        tmp[i]=ans[i];
        A_count=0;B_count=0;
        for(i=0;i<n;i++)
        scanf("%d",&guess[i]);
        if(!guess[0])
        break;
        for(i=0;i<n;i++)
        if(tmp[i]==guess[i])
        {A_count++;tmp[i]=0;guess[i]=-1;}
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(i!=j&&tmp[i]==guess[j])
        {B_count++;tmp[i]=0;guess[j]=-1;}
        printf("    (%d,%d)\n",A_count,B_count);
    }
    }
}
