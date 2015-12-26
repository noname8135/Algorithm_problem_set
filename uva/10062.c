#include <stdio.h>
#include <stdlib.h>
typedef struct gefdgs{
    int time;
    char alp;
}Set;
int cmp(const void* a,const void* b)
{
    Set A=*((Set*)a),B=*((Set*)b);
    if(A.time==B.time)
        return B.alp-A.alp;
    return A.time-B.time;
}
int main()
{
    Set set[1001];
    int i,j,counter=0,first=0;
    char str[1500];
    while(fgets(str,1499,stdin))
    {
        counter=0;
        for(i=0;str[i]!='\0'&&str[i]!='\n';i++)
        {
            if(str[i]<32||str[i]>128)
                continue;
            for(j=0;j<counter;j++)
            if(set[j].alp==str[i])
            {set[j].time++;break;}
            if(j==counter)
            {
                set[counter].alp=str[i];
                set[counter++].time=1;
            }
        }
        qsort(set,counter,sizeof(Set),cmp);
        if(first)
        printf("\n");
        else
            first=1;
        for(i=0;i<counter;i++)
        printf("%d %d\n",set[i].alp,set[i].time);
    }
}
