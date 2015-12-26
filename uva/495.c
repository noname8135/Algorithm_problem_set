#include <stdio.h>
#include <stdlib.h>
typedef struct BIGNUM{
    int digit;
    char *num;
}BigNum;
BigNum new_fab(BigNum fab_1,BigNum fab_2)
{
    int i,number;
    BigNum fab_3;
    fab_3.num=(char*)malloc(sizeof(char)*(fab_2.digit+2));
    fab_3.num[fab_2.digit]='0';
    fab_3.num[fab_2.digit+1]='0';
    for(i=0;i<fab_2.digit;i++)
    fab_3.num[i]=fab_1.num[i]+fab_2.num[i]-'0';
    for(i=0;i<fab_2.digit;i++)
        if(fab_3.num[i]>=10+'0')
        {fab_3.num[i]-=10;fab_3.num[i+1]++;}
    if(fab_3.num[fab_2.digit]=='1')
        fab_3.digit=fab_2.digit+1;
    else
        fab_3.digit=fab_2.digit;
    return fab_3;
}

int main()
{
    int i,number;
    BigNum fab[5002];
    fab[0].digit=1;fab[1].digit=1;
    fab[0].num=(char*)malloc(sizeof(char)*(fab[0].digit+1));
    fab[1].num=(char*)malloc(sizeof(char)*(fab[1].digit+1));
    fab[0].num[0]='0';fab[0].num[1]='0';
    fab[1].num[0]='1';fab[1].num[1]='0';
    for(i=2;i<=5000;i++)
    fab[i]=new_fab(fab[i-2],fab[i-1]);
    while(scanf("%d",&number)==1)
    {
        printf("The Fibonacci number for %d is ",number);
        for(i=fab[number].digit-1;i>=0;i--)
            printf("%c",fab[number].num[i]);
        printf("\n");
    }
    return 0;
}
