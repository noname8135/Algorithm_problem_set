#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int ana[10000];
int cmp(const void* a,const void* b)
{
    int i,tmp;
    for(i=0;;i++)
    if(((char*)a)[i]!=((char*)b)[i])
        return ((char*)a)[i]-((char*)b)[i];
}
int main()
{
    char word[10000][30],tmp;
    int word_count=0,i,flag=0,j,alp_count[10000][26],k;
    i=0;
    for(j=0;j<10000;j++)
        ana[j]=1;
    for(j=0;j<26;j++)
        alp_count[0][j]=0;
    while(scanf("%c",&tmp))
    {
        if(tmp=='#')
            break;
        else if(flag==0&&(tmp==' '||tmp=='\n'))
            continue;
        else if((tmp==' '||tmp=='\n')&&flag==1)
        {
            flag=0;
            for(j=0;j<word_count;j++)
            {
                for(k=0;k<26;k++)
                if(alp_count[j][k]!=alp_count[word_count][k])
                    break;
                if(k==26)
                {
                    ana[j]=0;
                    break;
                }
            }
            if(j==word_count)
            word[word_count++][i]='\0';
            else
            ana[j]=0;
            i=0;
            for(j=0;j<26;j++)
                alp_count[word_count][j]=0;
        }
        else
        {
            word[word_count][i++]=tmp;
            if(tmp>='a'&&tmp<='z')
                alp_count[word_count][tmp-'a']++;
            else if(tmp>='A'&&tmp<='Z')
                alp_count[word_count][tmp-'A']++;
            flag=1;
        }
    }
    for(i=0,j=0;i<word_count;i++)
    if(ana[i])
    strcpy(word[j++],word[i]);
    qsort(word,j,sizeof(word[0]),cmp);
    for(i=0;i<j;i++)
        printf("%s\n",word[i]);
    return 0;
}
