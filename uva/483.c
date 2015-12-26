#include <stdio.h>
#include <string.h>
int main()
{
    int i,j;
    char a[5000],temp[100];
    while(fgets(a,4000,stdin)!=NULL)
    {
        j=0;
        while(1)
        {
            sscanf(a+j,"%s",temp);
            for(i=strlen(temp)-1;i>=0;i--)
            printf("%c",temp[i]);
            j+=strlen(temp)+1;
            if(a[j]=='\0')
            {printf("\n");break;}
            else
            printf(" ");
        }

    }
    return 0;
}
