#include <stdio.h>
#include <string.h>
void print_big_int(int* a,int dig_num)
{
    int i;
    for(i=dig_num-1;i>=0;i--)
    printf("%d",a[i]);
    return ;
}
void fuck_leading_zero(char str[])
{
    if(str[0]=='0'&&str[1]=='\0')
    return;
    int i=0,j;
    while(str[i]=='0')
    i++;
    for(j=0;;j++,i++)
    {
        str[j]=str[i];
        if(str[j]=='\0')
        return;
    }
}
int mul(int* a,int a_dig_num,int* b,int b_dig_num,int* result)  //return dig_num of result
{
    int i,j;
    for(i=0;i<a_dig_num;i++)
    for(j=0;j<b_dig_num;j++)
    result[i+j]+=a[i]*b[j];
    for(i=0;i<a_dig_num+b_dig_num;i++)
    if(result[i]>10)
    {
        result[i+1]+=result[i]/10;
        result[i]%=10;
    }
    if(result[a_dig_num+b_dig_num-1]!=0)
    return a_dig_num+b_dig_num;
    return a_dig_num+b_dig_num-1;
}
int main()
{
    int i,X[500],Y[500],result[1000],res_dig_num;
    char temp1[500],temp2[500];
    while(scanf("%s%s",temp1,temp2)==2)
    {
         fuck_leading_zero(temp1);
         fuck_leading_zero(temp2);
         if((temp1[0]=='0'&&temp1[1]=='\0')||(temp2[0]=='0')&&temp2[1]=='\0')
         {
             printf("0\n");continue;
         }
         for(i=0;i<strlen(temp1);i++)
         X[strlen(temp1)-i-1]=temp1[i]-'0';
         for(i=0;i<strlen(temp2);i++)
         Y[strlen(temp2)-i-1]=temp2[i]-'0';
         memset(result,0,sizeof(int)*1000);
         res_dig_num=mul(X,strlen(temp1),Y,strlen(temp2),result);
         print_big_int(result,res_dig_num);
         printf("\n");
    }
    return 0;
}
