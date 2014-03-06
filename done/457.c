#include <stdio.h>
#include <string.h>
void print_situ(int a[])
{
    int i;
    for(i=0;i<40;i++)
    if(a[i]==0)
    printf(" ");
    else if(a[i]==1)
    printf(".");
    else if(a[i]==2)
    printf("x");
    else if(a[i]==3)
    printf("W");
    return ;
}
int main()
{
    int j,dish[40],n,DNA[10],i,temp[40],space;
    while(scanf("%d",&n)!=EOF)
    {
        space=n;
        while(n--)
    {
        if(space!=n+1)
        printf("\n");
        memset(dish,0,sizeof(dish));dish[19]=1;
        for(i=0;i<10;i++)
        scanf("%d",&DNA[i]);
        for(i=0;i<50;i++)
        {
            print_situ(dish);
            temp[0]=DNA[dish[0]+dish[1]];
            temp[39]=DNA[dish[39]+dish[38]];
            for(j=1;j<39;j++)
            temp[j]=DNA[dish[j-1]+dish[j]+dish[j+1]];
            for(j=0;j<40;j++)
            dish[j]=temp[j];
            printf("\n");
        }
    }}
    return 0;
}
