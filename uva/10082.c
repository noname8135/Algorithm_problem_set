#include <stdio.h>

int main()
{
    char word;
    char respond[46]={'A','V','X','S','W','D','F','G','U','H','J','K','N','B','I','O','Q','E','A','R','Y','C','Q','Z','T','9','`','1','2','3'
    ,'4','5','6','7','8'};
    while(scanf("%c",&word)!=EOF)
    {
        if(word>='A'&&word<='Z')
        printf("%c",respond[word-'A']);
        else if(word>='0'&&word<='9')
        printf("%c",respond[word-'0'+25]);
        else if(word==',')
        printf("M");
        else if(word=='-')
        printf("0");
        else if(word=='=')
        printf("-");
        else if(word=='.')
        printf(",");
        else if(word=='/')
        printf(".");
        else if(word=='\'')
        printf(";");
        else if(word==';')
        printf("L");
        else if(word=='[')
        printf("P");
        else if(word==']')
        printf("[");
        else if(word=='\\')
        printf("]");
        else
        printf("%c",word);
    }
    return 0;
}
