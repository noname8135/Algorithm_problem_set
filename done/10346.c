#include <stdio.h>

int main()
{
    int n,m,butt,have_count;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        have_count=0;butt=0;
        while(n!=0)
        {
            have_count+=n;
            butt+=n;
            n=butt/m;
            butt%=m;
        }
        printf("%d\n",have_count);
    }
    return 0;
}
