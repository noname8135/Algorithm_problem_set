#include <stdio.h>
long long int reverse(long long int n)
{
    int temp[100],i=0;
    long long new_num=0,k=1;
    while(n)
    {
        temp[i++]=n%10;
        n/=10;
    }
    while(temp[--i]==0);
    while(1)
    {
        new_num+=k*temp[i];
        if(!i)
        return new_num;
        i--;
        k*=10;
    }
}
int main()
{
    int n,counter;
    long long int m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld",&m);
        if(m==0)
        {printf("1 0\n");continue;}
        counter=0;
        while(1)
        {
            m=m+reverse(m);
            counter++;
            if(m==reverse(m))
            break;
        }
        printf("%d %lld\n",counter,m);
    }
    return 0;
}
