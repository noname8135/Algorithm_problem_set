#include <stdio.h>
#include <string.h>
int main()
{
    int upr[26],lwr[26],max=0,i;
    char tmp[1000];
    while(fgets(tmp,1000,stdin)!=NULL)
    {
        memset(upr,0,sizeof(int)*26);
        memset(lwr,0,sizeof(int)*26);
        for(i=0;i<strlen(tmp);i++)
        {
            if(tmp[i]>='A'&&tmp[i]<='Z')
            upr[tmp[i]-'A']++;
            else if(tmp[i]>='a'&&tmp[i]<='z')
            lwr[tmp[i]-'a']++;
        }
        max=0;
        for(i=0;i<26;i++)
        {
            if(max<upr[i])
            max=upr[i];
            if(max<lwr[i])
            max=lwr[i];
        }
        for(i=0;i<26;i++)
        if(upr[i]==max)
        printf("%c",(char)i+'A');
        for(i=0;i<26;i++)
        if(lwr[i]==max)
        printf("%c",(char)i+'a');
        printf(" %d\n",max);
    }
    return 0;
}
