#include <stdio.h>

int main()
{
    double old_p,new_p,frag_old,frag_new,ans;
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        b=a+b;
        old_p=10000/(double)a;
        frag_old=old_p;
        new_p=10000/(double)b;
        frag_new=new_p;
        ans=0;
        while(old_p<10000&&new_p<10000)
        {
            while(new_p<old_p&&new_p<10000)
                new_p+=frag_new;
            if(new_p>=10000)
                break;
            ans+=(new_p-old_p>old_p-new_p+frag_new)?old_p-new_p+frag_new:new_p-old_p;
            old_p+=frag_old;
        }
        printf("%.4lf\n",ans);
    }
    return 0;
}
