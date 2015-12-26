#include <stdio.h>
int counter[6];
void print(int num)
{
    int i;
    if(num==0)
        return ;
    else if(num<4)
    {
        for(i=0;i<num;i++)
            counter[0]++;
    }
    else if(num==4)
    {
        counter[0]++;
        counter[1]++;
    }
    else if(num==100)
    counter[4]++;
    else if(num>=90)
    {
        counter[2]++;
        counter[4]++;
        return print(num-90);
    }
    else if(num>=50)
    {
        counter[3]++;return print(num-50);
    }
    else if(num>=40)
    {
        counter[2]++;
        counter[3]++;
        return print(num-40);
    }
    else if(num>=10)
    {
        while(num>=10)
        {
            counter[2]++;
            num-=10;
        }
        return print(num);
    }
    else if(num==9)
    {
        counter[0]++;
        counter[2]++;
    }
    else if(num>=5)
    {counter[1]++;return print(num-5);}
    return;
}
int main()
{
    int i,num;
    while(scanf("%d",&num)&&num)
    {
        for(i=0;i<5;i++)
        counter[i]=0;
        for(i=1;i<=num;i++)
        print(i);
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",num,counter[0],counter[1],counter[2],counter[3],counter[4]);
    }
    return 0;
}
