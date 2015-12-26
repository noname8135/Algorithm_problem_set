#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    int n,length;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",str);
        length=strlen(str);
        if(!strcmp(str,"1")||!strcmp(str,"4")||!strcmp(str,"78"))
        printf("+\n");
        else if(str[length-2]=='3'&&str[length-1]=='5')
        printf("-\n");
        else if(str[0]=='9'&&str[length-1]=='4')
        printf("*\n");
        else
        printf("?\n");
    }
    return 0;
}
