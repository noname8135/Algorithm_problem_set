#include<stdio.h>
#include <stdbool.h>
int prime[20];
bool used[20];
bool Is_prime(int num)
{
    int i;
    for(i=0;prime[i]<=num;i++)
        if(prime[i]==num)
        return 1;
    return 0;
}
void per(int ary[],int n,int cur)
{
    int i;
    if(n==cur)
    {
        if(!Is_prime(ary[0]+ary[n-1]))
        return;
        for(i=0;i<n;i++)
        if(i!=n-1)
            printf("%d ",ary[i]);
        else
            printf("%d\n",ary[i]);
    }

    for(i=2;i<=n;i++)
    {
        if(!used[i]&&Is_prime(ary[cur-1]+i))
        {
            used[i]=1;
            ary[cur]=i;
            per(ary,n,cur+1);
            used[i]=0;
        }
    }
    return ;
}
int main()
{
    int i,counter=1,j,ary[20],n;
    prime[0]=2;
    for(i=3;counter<20;i+=2)
    {
        for(j=2;j*j<=i;j++)
        if(i%j==0)
        break;
        if(j*j>i)
            prime[counter++]=i;
    }
    counter=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(counter)
            printf("\n");
        printf("Case %d:\n",++counter);
        for(i=1;i<=n;i++)
            used[i]=0;
        ary[0]=1;
        per(ary,n,1);
    }
    return 0;
}
