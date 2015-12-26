#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool check_jelly(bool* a,int n)
{
    while(--n)
    if(!a[n])
    return 0;
    return 1;
}
int main()
{
    bool flag[3001];
    int i,n,num1,num2;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&num1);
        if(n==1)
        {printf("Jolly\n");continue;}
        memset(flag,0,sizeof(bool)*n);
        i=n;
        n--;
        while(n--)
        {
            scanf("%d",&num2);
            flag[(num1>num2?num1-num2:num2-num1)]=1;
            num1=num2;
        }
        if(check_jelly(flag,i))
        printf("Jolly\n");
        else
        printf("Not jolly\n");
    }
    return 0;
}
