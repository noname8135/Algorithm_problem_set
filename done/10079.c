#include <stdio.h>

int main()
{
    long long int n;
    while(scanf("%lld",&n)&&n>=0)
    printf("%lld\n",(n+1)*n/2+1);
    return 0;
}
