#include <stdio.h>
#include <stdbool.h>
#include <string.h>
double value(char str[],bool* flag) /*str[0] will be the concept if legal*/
{
    int i=2;
    float value;
    if((str[0]=='P'||str[0]=='U'||str[0]=='I')&&str[1]=='=')
    {
        sscanf(str+2,"%f",&value);
        while(str[i]!='m'&&str[i]!='k'&&str[i]!='M'&&str[i]!='W'&&str[i]!='V'&&str[i]!='A')
        if(str[i++]=='\0')
        {*flag=0;return 0;}
        if(str[i]=='m')
        {value=value*0.001;i++;}
        else if(str[i]=='k')
        {value=value*1000;i++;}
        else if(str[i]=='M')
        {value=value*1000000;i++;}
        if(str[i]!='W'&&str[i]!='V'&&str[i]!='A')
        {*flag=0;printf("\nthe should not judge=%c\n\n",str[i]);return -1;}
        *flag=1;
        return value;
    }
    *flag=0;return -1;
}
int main()
{
    //P U I
    double ans,a[2];
    bool legality;
    int n,walker,i,j;
    char temp[20],str[100],prefix[3];
    scanf("%d\n",&n);
    j=1;
    while(n--)
    {
        printf("Problem #%d\n",j);
        j++;
        fgets(str,299,stdin);
        if(str[strlen(str)-1]=='\n')
        str[strlen(str)-1]='\0';
        walker=0;i=0;
        while(str[walker]!='\0')
        {
            sscanf(str+walker,"%s",temp);
            a[i]=value(temp,&legality);
            if((int)a[i]!=-1)
            {
                prefix[i]=temp[0];
                i++;
            }
            walker+=strlen(temp);
            while(str[walker]==' ')
            walker++;
        }
        if(prefix[0]=='I'&&prefix[1]=='P')
        printf("U=%.2fV\n",a[1]/a[0]);
        else if(prefix[0]=='P'&&prefix[1]=='I')
        printf("U=%.2fV\n",a[0]/a[1]);
        else if(prefix[0]=='P'&&prefix[1]=='U')
        printf("I=%.2fA\n",a[0]/a[1]);
        else if(prefix[0]=='U'&&prefix[1]=='P')
        printf("I=%.2fA\n",a[1]/a[0]);
        else
        printf("P=%.2fW\n",a[0]*a[1]);
        printf("\n");
    }
    return 0;
}
