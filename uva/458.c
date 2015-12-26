#include <stdio.h>
int main()
{
    char a;
    while(scanf("%c",&a)!=EOF)
    printf("%c",a=='\n'?a:a-7);
    return 0;
}
