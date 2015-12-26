#include <stdio.h>
int found(int L,int number_num,int a[])
{
    int i;
    for(i=0;i<number_num;i++)
    if(a[i]==L)
    return i;
    return -1;
}
int main()
{
    int loop_count,case_count=0,first_num,a[10000];
    int k,Z,I,M,L,i;
    while(scanf("%d%d%d%d",&Z,&I,&M,&L))
    {
    if(!Z&&!I&&!M&&!L)
    return 0;
    printf("Case %d: ",++case_count);
    first_num=L;
    loop_count=1;
    a[0]=L;
    while(1)
    {
        L=(Z*L+I)%M;
        if((k=found(L,loop_count,a))!=-1)
        break;
        a[loop_count]=L;
        loop_count++;
    }
    printf("%d\n",loop_count-k);
    }
}
