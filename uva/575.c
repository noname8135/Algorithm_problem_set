#include <stdio.h>
#include <string.h>
int trans(char a,int n) //2^n-1
{
    if(a=='0')
    return 0;
    int k=1;
    while(n--)
    k*=2;
    k--;
    return (a-'0')*k;
}
int main()
{
    char str[200];
    int i,temp;
    while(scanf("%s",str))
    {
        if(str[0]=='0'&&str[1]=='\0')
        return 0;
        for(i=0,temp=0;i<strlen(str);i++)
        temp+=trans(str[i],strlen(str)-i);
        printf("%d\n",temp);
    }
}
