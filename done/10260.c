#include <stdio.h>

int main()
{
    char sound[2000];
    int i,j,ary[2000];
    while(fgets(sound,1999,stdin))
    {
        for(i=0;sound[i]!='\0';i++)
        {
            if(sound[i]=='R')
            ary[i]=6;
            else if(sound[i]=='L')
            ary[i]=4;
            else if(sound[i]=='M'||sound[i]=='N')
            ary[i]=5;
            else if(sound[i]=='D'||sound[i]=='T')
            ary[i]=3;
            else if(sound[i]=='B'||sound[i]=='F'||sound[i]=='P'||sound[i]=='V')
            ary[i]=1;
            else if(sound[i]=='C'||sound[i]=='G'||sound[i]=='J'||sound[i]=='K'||sound[i]=='Q'||sound[i]=='S'||sound[i]=='X'||sound[i]=='Z')
            ary[i]=2;
            else
            ary[i]=0;
        }
        for(j=0;j<i;j++)
        {
            if(j&&ary[j]==ary[j-1])
                continue;
            if(ary[j]!=0)
            printf("%d",ary[j]);
        }
        printf("\n");
    }
    return 0;
}
