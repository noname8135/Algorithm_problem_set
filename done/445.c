#include <stdio.h>
#include <stdlib.h>
int main()
{
    char temp[2];
    temp[1]='\0';
    int repeat_time=0;
    while(scanf("%c",&temp[0])!=EOF)
    {
        if(temp[0]>='0'&&temp[0]<='9')
        repeat_time+=atoi(temp);
        else
        {
            if(temp[0]=='b')
            while(repeat_time--)
            printf(" ");
            else if(temp[0]=='*'||(temp[0]>='A'&&temp[0]<='Z'))
            while(repeat_time--)
            printf("%c",temp[0]);
            else if(temp[0]=='\n'||temp[0]=='!')
            {printf("\n");repeat_time=-1;}
            repeat_time++;
        }
    }
    return 0;
}
