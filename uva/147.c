#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int j,i,amount;
    int token[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
    char tmp[10];
    long long int* ways;
    ways=(long long int*)malloc(sizeof(long long int)*30002);
    for(i=0;i<5;i++)
    ways[i]=1;
    for(i=5;i<30001;i++)
        ways[i]=0;
    for(i=0;i<11;i++)
        for(j=token[i];j<=30000;j++)
        {
            ways[j]+=ways[j-token[i]];
        }
    while(scanf("%s",tmp)&&strcmp(tmp,"0.00"))
    {
        printf("%6s",tmp);
        for(i=0;tmp[i]!='.';i++)
            ;
        if(tmp[i+1]!='\0'&&tmp[i+2]!='\0')
        tmp[i+3]='\0';
        for(;;i++)
            {tmp[i]=tmp[i+1];
            if(tmp[i]=='\0')
                break;}
        amount=atoi(tmp);
        printf("%17lld\n",ways[amount]);
    }
    return 0;
}
