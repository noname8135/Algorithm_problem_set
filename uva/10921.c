#include <stdio.h>
int main()
{
    char word;
    int A_to_I[30]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    {
        while(scanf("%c",&word)!=EOF)
        {
            if(word>='A'&&word<='Z')
            printf("%d",A_to_I[word-'A']);
            else
            printf("%c",word);
        }
    }
    return 0;
}
