#include <stdio.h>

int main()
{
    char temp;
    int i,max,alp_appear[27]={0},flag=1;
    while(scanf("%c",&temp)!=EOF)
    {
        if(temp>='a'&&temp<='z')
        temp-=' ';
        if(temp>='A'&&temp<='Z')
        alp_appear[temp-'A']++;
    }
    flag=0;
    while(1)
    {
    for(i=0,max=0;i<26;i++)
    {
        if(alp_appear[i]>max)
        max=alp_appear[i];
    }
    if(!max)
    break;
    for(i=0;i<26;i++)
    {
        if(alp_appear[i]==max)
        {
            printf("%c %d\n",(char)(i+'A'),max);
            alp_appear[i]=0;
        }
    }
    }
}
