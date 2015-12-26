#include <stdio.h>
#include <string.h>
int main()
{
    char str[101][101];
    int i,line_count=0,j=0,max_length=0,str_len[101];
    while(scanf("%c",&str[line_count][j])!=EOF)
    {
        if(str[line_count][j]=='\n')
        {
            if(j>max_length)
            max_length=j;   //get the length of the string that has the longest length among all the strings
            str_len[line_count]=j;   //store every length of string
            str[line_count][j]='\0';//create a legal string once a \n is met
            line_count++;j=0;
        }
        else
        j++;
    }
    for(j=0;j<max_length;j++)
    {
        for(i=line_count-1;i>=0;i--)
        {
            if(str_len[i]>j)
            printf("%c",str[i][j]);
            else
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
