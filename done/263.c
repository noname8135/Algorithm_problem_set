#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a,const void* b)
{
    return (*((int*)a)-*((int*)b));
}
int appeared(int num,int before[],int n)
{
    int i;
    for(i=0;i<n;i++)
        if(num==before[i])
        return 1;
    return 0;
}
int main()
{
    int a,b,i,num,tmp,k;
    int parsed[11],len,last,dg_count,before[200],bn,flag=0;
    while(scanf("%d",&num)&&num)
    {
         printf("Original number was %d\n",num);
         len=0;last=num;bn=0;
         while(1)
         {
             len++;
             tmp=last;dg_count=0;
                while(last)//parse it
         {
             parsed[dg_count++]=last%10;
             last/=10;
         }
         last=tmp;
         qsort(parsed,dg_count,sizeof(int),cmp);
         a=0;k=1;
         for(i=0;i<dg_count;i++)
         {
             a+=parsed[i]*k;
             k*=10;
         }
         printf("%d - ",a);
         b=0;k=1;
         for(i=dg_count-1;i>=0;i--)
         {
             b+=parsed[i]*k;
             k*=10;
         }
         printf("%d = %d\n",b,a-b);
         if(appeared(a-b,before,bn))
            break;
         before[bn++]=a-b;
        last=a-b;
         }
         printf("Chain length %d\n\n",len);
    }
    return 0;
}
