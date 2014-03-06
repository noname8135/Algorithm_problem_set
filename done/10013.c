#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *a,*b,*ans;
    a=(char*)malloc(10000001);
    b=(char*)malloc(10000001);
    ans=(char*)malloc(10000001);
    int carry,n,m,i,len;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d\n",&m);
        for(i=0;i<m;i++)
            scanf("%c %c\n",&a[i],&b[i]);
        carry=0;
        len=0;
        for(i=m-1;i>=0;i--)
        {
            if(carry==1)
                a[i]+=1;
            if(a[i]+b[i]-'0'*2>=10)
            carry=1;
            else
            carry=0;
            ans[len++]=(a[i]+b[i]-'0'*2)%10+'0';
        }
        if(carry)
            printf("1");
        for(i=len-1;i>=0;i--)
            printf("%c",ans[i]);
        printf("\n");
        if(n)
        printf("\n");
    }
    return 0;
}
