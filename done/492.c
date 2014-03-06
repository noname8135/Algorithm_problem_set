#include <stdio.h>

int main()
{
    int i,word_letter;
    char str,word[500];
    word_letter=0;
    while(scanf("%c",&str)!=EOF)
    {
        if((str>='a'&&str<='z')||(str>='A'&&str<='Z'))
            {
                word[word_letter++]=str;
            }
            else
            {
                word[word_letter]='\0';
                if(word_letter)
                if(word[0]=='a'||word[0]=='e'||word[0]=='i'||word[0]=='o'||word[0]=='u'||word[0]=='A'||word[0]=='E'||word[0]=='I'||word[0]=='O'||word[0]=='U')
                {
                    printf("%s",word);
                    printf("ay");
                }
                else
                {
                    printf("%s",word+1);
                    printf("%c",word[0]);
                    printf("ay");
                }
                printf("%c",str);
                word_letter=0;
            }
        }
    return 0;
}
