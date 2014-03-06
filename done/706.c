#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int main()
{
    int size,i,j,time;
    bool show[20][8];
    char num[20];
    while(scanf("%d %s",&size,num)&&(num[0]!='0'||num[1]!='\0'||size))
    {
        for(i=0;i<strlen(num);i++)
            {
                if(num[i]=='1'||num[i]=='2'||num[i]=='3'||num[i]=='7')
                show[i][1]=0;
                else
                show[i][1]=1;

                if(num[i]=='1'||num[i]=='4')
                show[i][0]=0;
                else
                show[i][0]=1;

                if(num[i]=='5'||num[i]=='6')
                show[i][2]=0;
                else
                show[i][2]=1;

                if(num[i]=='1'||num[i]=='7'||num[i]=='0')
                show[i][3]=0;
                else
                show[i][3]=1;

                if(num[i]=='2'||num[i]=='6'||num[i]=='8'||num[i]=='0')
                show[i][4]=1;
                else
                show[i][4]=0;

                if(num[i]=='1'||num[i]=='4'||num[i]=='7')
                show[i][6]=0;
                else
                show[i][6]=1;

                if(num[i]=='2')
                show[i][5]=0;
                else
                show[i][5]=1;
            }
        for(i=0;i<strlen(num);i++)
        {
            printf(" ");
            for(time=0;time<size;time++)
            if(show[i][0])
            printf("-");
            else
            printf(" ");
            printf(" ");
            if(i!=strlen(num)-1)
            printf(" ");
            else
            printf("\n");
        }
        for(time=0;time<size;time++)
        for(i=0;i<strlen(num);i++)
        {
                if(show[i][1])
                printf("|");
                else
                printf(" ");
                for(j=0;j<size;j++)
                printf(" ");
                if(show[i][2])
                printf("|");
                else
                printf(" ");
                if(i!=strlen(num)-1)
                printf(" ");
                else
                printf("\n");
        }
        for(i=0;i<strlen(num);i++)
        {
            printf(" ");
            for(time=0;time<size;time++)
            if(show[i][3])
            printf("-");
            else
            printf(" ");
            printf(" ");
            if(i!=strlen(num)-1)
            printf(" ");
            else
            printf("\n");
        }
        for(time=0;time<size;time++)
        for(i=0;i<strlen(num);i++)
        {
                if(show[i][4])
                printf("|");
                else
                printf(" ");
                for(j=0;j<size;j++)
                printf(" ");
                if(show[i][5])
                printf("|");
                else
                printf(" ");
                if(i!=strlen(num)-1)
                printf(" ");
                else
                printf("\n");
        }
        for(i=0;i<strlen(num);i++)
        {
            printf(" ");
            for(time=0;time<size;time++)
            if(show[i][6])
            printf("-");
            else
            printf(" ");
            printf(" ");
            if(i!=strlen(num)-1)
            printf(" ");
            else
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
