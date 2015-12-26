#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int if_legal(int n,int m,bool* turned)
{
    //printf("m=%d\n",m);
    int i=0,j=0,counter=0,last_j=-1;
    while(1)
    {
       // printf("%d %d\n",i,j);
        if(j==0&&last_j)
        {
            if(turned[i]==0&&i!=12)
            {turned[i]=1;counter++;//printf("counter=%d\n",counter);
            if(counter==n-1)
            return 1;}
            else
            return 0;
        }
        i++;
        i%=n;
        last_j=j;
        if(turned[i]==0)
        j++;
        j%=m;
    }
}
int main()
{
    bool turned[100];
    int n,i;
    while(scanf("%d",&n)&&n)
    {
        if(n==13)
        {printf("1\n");continue;}
        for(i=2,memset(turned,0,sizeof(bool)*n);if_legal(n,i,turned)==0;i++,memset(turned,0,sizeof(bool)*n))
        ;
        printf("%d\n",i);
    }
    return 0;
}
