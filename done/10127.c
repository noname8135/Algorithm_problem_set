#include<stdio.h>
int min_dividable_one(int num)  //return number of 1s in the minimum dividable 1111....
{
    int remainder=1,one_counter=1;
    while(remainder)
    {
        if (remainder<num)
        {
            remainder=remainder*10+1;
            one_counter++;
        }
        remainder%=num;
    }
    return one_counter;
}
int main()
{
    int num;
    while(scanf("%d",&num)!=EOF)
    {
        printf("%d\n",min_dividable_one(num));
    }
    return 0;
}
