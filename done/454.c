#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void* a,const void* b)
{
    int i;
    for(i=0;;i++)
    {
       if(((char*)a)[i]!=((char*)b)[i])
        return ((char*)a)[i]-((char*)b)[i];
    }
}
int main()
{
    int i,j,k,t,str_count,alp_appear[200][128];
    char str[200][500];
    scanf("%d\n\n",&t);
    while(t--)
    {
        str_count=0;
        while(fgets(str[str_count],499,stdin))
        {
            if(str[str_count][0]=='\n')
                break;
            if(str[str_count][strlen(str[str_count])-1]=='\n')
            str[str_count][strlen(str[str_count])-1]='\0';
            for(i=0;i<128;i++)
                alp_appear[str_count][i]=0;
            str_count++;
        }
        qsort(str,str_count,sizeof(str[0]),cmp);
        for(i=0;i<str_count;i++)
            for(j=0;str[i][j]!='\0';j++)
            if(str[i][j]!=' ')
            alp_appear[i][str[i][j]]++;
        for(i=0;i<str_count-1;i++)
        for(j=i+1;j<str_count;j++)
        {
            for(k=0;k<128;k++)
            if(alp_appear[i][k]!=alp_appear[j][k])
            break;
            if(k==128)
                printf("%s = %s\n",str[i],str[j]);
        }
        if(t)
            printf("\n");
    }
    return 0;
}
