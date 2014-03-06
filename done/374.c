#include <stdio.h>
int main()
{
    int P,M,ans;
    long long int B;
    while(scanf("%lld%d%d",&B,&P,&M)==3)
    {
        ans=1;
        while(P)
        {
            B%=M;
            if(P%2)
            {ans*=B;ans%=M;}
            P/=2;
            B*=B;
        }
        printf("%d\n",ans);
    }
    return 0;
}
