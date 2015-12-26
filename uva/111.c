#include <stdio.h>
#include <stdbool.h>
bool right_order(int ans[],int a,int b,int n)//a should be before b
{
    int i,j;
    for(i=0;i<n;i++)
    if(ans[i]==a)
    break;
    for(j=0;j<n;j++)
    if(ans[j]==b)
    break;
    if(i<j)
        return 1;
    return 0;
}
int result(int ans[],int student[],int n)
{
    int i,stage[20],j;
    for(i=0;i<n;i++)
        stage[i]=1;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        if(right_order(ans,student[i],student[j],n)&&stage[i]+1>stage[j])
        stage[j]=stage[i]+1;
    int max=0;
    for(i=0;i<n;i++)
        if(max<stage[i])
        max=stage[i];
    return max;
}
int main()
{
    int i,j,n,ans[21],student[21],tmp;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            {
                scanf("%d",&tmp);
                ans[tmp-1]=i;
            }
        while(scanf("%d",&tmp)!=EOF)
        {
            student[tmp-1]=0;
            for(j=1;j<n;j++)
            {
                scanf("%d",&tmp);
                student[tmp-1]=j;
            }
            printf("%d\n",result(ans,student,n));
        }
    }
    return 0;
}
