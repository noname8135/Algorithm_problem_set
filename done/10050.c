#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int main()
{
    bool sit[6000];
    int i,j,counter,n,days,party_num,party[101];//sit = situation of each day
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&days,&party_num);
        memset(sit,0,sizeof(bool)*days);
        for(i=0;i<party_num;i++)
        scanf("%d",&party[i]);
        for(counter=0,i=0;i<days;i++)
        {
            if(i%7==5||i%7==6)
            continue;
            for(j=0;j<party_num;j++)
            if((i+1)%party[j]==0&&sit[i]==0)
            {
                sit[i]=1;counter++;
            }
        }
        printf("%d\n",counter);
    }
    return 0;
}
