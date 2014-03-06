#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
void calculate(char str1[],char str2[],int len1,int len2)
{
    int sub[MAX+2][MAX+2]={0},i,j;
    for(i=1;i<=len1;i++)
    {
        for(j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                sub[i][j]=sub[i-1][j-1]+1;
            }
            else
                sub[i][j]=(sub[i][j-1]>sub[i-1][j])?sub[i][j-1]:sub[i-1][j];
        }
    }
    printf("%d\n",sub[len1][len2]);
    return ;
}
int main()
{
    char str1[1001],str2[1001];
    int i;
    while(fgets(str1,1000,stdin)&&fgets(str2,1000,stdin))
    {
        i=0;
        while(str1[i]!='\n'&&str1[i]!='\0')
            i++;
        str1[i]='\0';
        i=0;
        while(str2[i]!='\n'&&str2[i]!='\0')
            i++;
        str2[i]='\0';
        calculate(str1,str2,strlen(str1),strlen(str2));
    }
    return 0;
}
