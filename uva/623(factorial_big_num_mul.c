#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* next_factorial(char* multiplicand,int multiplier)
{
    int i;
    int* ans;
    char* ans_char;
    ans=(int*)malloc(sizeof(int)*3001);
    for(i=0;multiplicand[i]!='\0';i++)
        ans[i]=0;
    ans[i]=0;ans[i+1]=0;ans[i+2]=0;ans[i+3]=0;
    ans_char=(char*)malloc(sizeof(char)*(i+15));
    for(i=0;multiplicand[i]!='\0';i++)
    {
        ans[i]+=((multiplicand[i]-'0')*multiplier);
        if(ans[i]>=10)
        {
            ans[i+1]+=ans[i]/10;
            ans[i]%=10;
        }
        ans_char[i]=ans[i]+'0';
    }
    for(;ans[i]>=10;i++)
    {
        ans[i+1]+=(ans[i]/10);
        ans[i]%=10;
        ans_char[i]=(ans[i]+'0');
    }
    if(ans[i]==0)
    ans_char[i]='\0';    //same as '\0'
    else
    {ans_char[i]=ans[i]+'0';ans_char[i+1]='\0';}
    return ans_char;
}
int main()
{
    int num,size,i,j;
    char **factorial;
    factorial=(char**)malloc(sizeof(char*)*1005);
    for(i=0;i<3;i++)
        {
            factorial[i]=(char*)malloc(sizeof(char)*2);
            factorial[i][1]='\0';
        }
    factorial[0][0]='1';
    factorial[1][0]='1';
    factorial[2][0]='2';
    for(i=3;i<=1000;i++)
    factorial[i]=next_factorial(factorial[i-1],i);
    while(scanf("%d",&num)!=EOF)
    {
        printf("%d!\n",num);
        for(i=strlen(factorial[num])-1;i>=0;i--)
        printf("%c",factorial[num][i]);
        printf("\n");
    }
    return 0;
}
