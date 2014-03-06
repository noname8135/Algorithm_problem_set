#include <stdio.h>
#include <string.h>
int if_last(int* at,int n,int num)
{
    int i;
    for(i=0;i<=n;i++)
    if(at[i]==num)
    return 0;
    return 1;
}
int main()
{
    int i,j,n,position,max,min,height[60],case_count=0;
    char trend[60];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",trend);
        printf("Case #%d:\n",++case_count);
        position=0;max=0;min=0;height[0]=0;
        for(i=1;i<strlen(trend);i++)
        {
            if(trend[i-1]=='R'&&(trend[i]=='R'||trend[i]=='C'))
            height[i]=height[i-1]+1;
            else if(trend[i-1]=='C'&&trend[i]=='F')
            height[i]=height[i-1]-1;
            else if(trend[i-1]=='F'&&trend[i]=='F')
            height[i]=height[i-1]-1;
            else
            height[i]=height[i-1];
            if(max<height[i])
            max=height[i];
            if(min>height[i])
            min=height[i];
        }
        for(i=max;i>=min;i--)
        {
            printf("| ");
            for(j=0;j<strlen(trend);j++)
            if(height[j]==i)
            {
                if(trend[j]=='R')
                printf("/");
                else if(trend[j]=='C')
                printf("_");
                else if(trend[j]=='F')
                printf("\\");
            }
            else if(!if_last(height+j,strlen(trend)-j-1,i))
            printf(" ");
            printf("\n");
        }
        printf("+");
        for(i=0;i<=strlen(trend)+1;i++)
        printf("-");
        printf("\n");
        printf("\n");
    }
    return 0;
}
