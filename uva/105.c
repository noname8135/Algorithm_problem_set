#include <stdio.h>

int main()
{
    int skyline[10001]={0},left,right,height,i,most_left=5000,most_right=0;
    while(scanf("%d %d %d",&left,&height,&right)!=EOF)
    {
        if(left<most_left)
            most_left=left;
        if(right>most_right)
            most_right=right;
        for(i=left;i<right;i++)
            if(skyline[i]<height)
            skyline[i]=height;
    }
    printf("%d %d",most_left,skyline[most_left]);
    for(i=most_left;i<most_right;i++)
        {
            if(skyline[i]!=skyline[i+1])
            printf(" %d %d",i+1,skyline[i+1]);
        }
        printf("\n");
    return 0;
}
