#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *a,*b;
    a=(char*)malloc(sizeof(char)*500000);
    b=(char*)malloc(sizeof(char)*500000);
    int i,j;
    while(scanf("%s%s",a,b)==2)
    {
        i=0;j=0;
        while(a[i]!='\0'&&b[j]!='\0')
        {
            if(a[i]==b[j])
            i++;
            j++;
        }
        if(a[i]=='\0')
        printf("Yes\n");
        else
        printf("No\n");
    }
    return 0;
}
