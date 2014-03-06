#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int cmp(const void* a,const void* b)
{
    int a_value,b_value;
    if(*((char*)a)>='A'&&*((char*)a)<='Z')
    a_value=*((char*)a)-'A';
    else
    a_value=*((char*)a)-'a';

    if(*((char*)b)>='A'&&*((char*)b)<='Z')
    b_value=*((char*)b)-'A';
    else
    b_value=*((char*)b)-'a';

    if(a_value==b_value)
        return *((char*)a)-*((char*)b);
    else
        return a_value-b_value;
}

void permu(int* ary,int now,int n,char* str,bool* used)
{
    int i,j;
    char just='\0';
    if(now==n)
    {
        for(i=0;i<n;i++)
            printf("%c",str[ary[i]]);
        printf("\n");
        return ;
    }
    for(i=0;i<n;i++)
    {
        if(used[i]==0&&str[i]!=just)
        {
            ary[now]=i;
            used[i]=1;
            permu(ary,now+1,n,str,used);
            used[i]=0;
            just=str[i];
        }
    }
    return ;
}
int main()
{
    bool found,used[1000];
    int i,j,k,n,tmp,per[1000],counter;
    char str[1000],now[1000],last[1000];
    char **ans;

    ans=(char**)malloc(sizeof(char*)*1000000);
    for(i=0;i<10000;i++)
        ans[i]=(char*)malloc(1000);
    scanf("%d",&n);
    last[0]='\0';
    while(n--)
    {
        scanf("%s",str);
        for(i=0;i<strlen(str);i++)
            per[i]=i;
        qsort(str,strlen(str),sizeof(char),cmp);
        permu(per,0,strlen(str),str,used);
    }
    return 0;
}
