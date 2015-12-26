#include <stdio.h>
#include <stdbool.h>
void print(int*);
void mul(int *a,bool* a_sign, int num)
{
    int i;
    if(num<0)
    {
        num*=-1;
        *a_sign=!(*a_sign);
    }
    for(i=0;i<1000;i++)
    a[i]*=num;

    for(i=0;i<1000;i++)
        if(a[i]>=10)
        {
            a[i+1]+=(a[i]/10);
            a[i]%=10;
        }
    return ;
}
void assign(int* a,bool* a_sign,int num)
{
    int i=0;
    if(num<0)
        {
            *a_sign=0;
            num*=-1;
        }
    else
        *a_sign=1;
    while(num)
    {
        a[i++]=num%10;
        num/=10;
    }
    for(;i<1000;i++)
        a[i]=0;
    return ;
}
void assign_big(int* a,bool* a_sign,int* b,bool b_sign)
{
    *a_sign=b_sign;
    int i;
    for(i=0;i<1000;i++)
        a[i]=b[i];
    return ;
}
bool bigger(int* a,bool a_sign,int* b,bool b_sign)
{
    int i=1000;
    bool flag=0;
    if(a_sign&&!b_sign)
        return 1;
    else if(!a_sign&&b_sign)
        return 0;
    else if(!a_sign&&!b_sign)
        flag=1;
    while(i--)
    {
        if(a[i]<b[i])
            return flag;
        else if(a[i]>b[i])
            return !flag;
    }
    return flag;
}
void print(int* a)
{
    int i=1000;
        while(i&&a[i]==0)
            i--;
        int j;
        for(j=i;j>=0;j--)
            printf("%d",a[j]);
        printf("\n");
    return ;
}
int main()
{
    int max[10000],acc[10000];
    int i,j,ary[1000],counter;
    bool max_pos,acc_pos;       //positive or negative
    while(scanf("%d",&ary[0])!=EOF)
    {
        counter=1;
        while(scanf("%d",&ary[counter]))
        {
            if(ary[counter]==-999999)
            break;
            else
            counter++;
        }
        for(i=0;i<2000;i++)
            {max[i]=0;acc[i]=0;}
        max[800]=9;
        max_pos=0;
        for(i=0;i<counter;i++)
        {
            assign(acc,&acc_pos,ary[i]);
            print(acc);
            if(bigger(acc,acc_pos,max,max_pos))
                assign_big(max,&max_pos,acc,acc_pos);
            for(j=i+1;j<counter;j++)
            {
                mul(acc,&acc_pos,ary[j]);
                print(acc);
                if(bigger(acc,acc_pos,max,max_pos))
                    assign_big(max,&max_pos,acc,acc_pos);
            }
        }
        if(!max_pos)
            printf("-");
        print(max);
    }
    return 0;
}
