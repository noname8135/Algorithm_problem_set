#include <stdio.h>
#include <stdlib.h>
typedef struct ELEPHANT{
    int weight;
    int IQ;
    int index;
}Elephant;

Elephant ele[1001];

int cmp(const void* a,const void* b)
{
    if((*((Elephant*)a)).weight==(*((Elephant*)b)).weight)
        return (*((Elephant*)b)).IQ-(*((Elephant*)a)).IQ;
    return (*((Elephant*)a)).weight-(*((Elephant*)b)).weight;
}

int main()
{
    int k,max,max_i,i,w,iq,count=0;
    int* ary[1003];
    int j,sofar[1001];
    while(scanf("%d%d",&w,&iq)==2)
    {
        ele[count].weight=w;
        ele[count].index=count+1;
        ele[count++].IQ=iq;
    }
    qsort(ele,count,sizeof(Elephant),cmp);

    for(i=0;i<count;i++)
        {
            sofar[i]=1;
            ary[i]=(int*)malloc(sizeof(int)*i+1);
            ary[i][0]=i;
        }
    max=0;
    for(i=0;i<count-1;i++)
    for(j=i+1;j<count;j++)
    {
        if(ele[i].IQ>ele[j].IQ&&sofar[i]+1>sofar[j]&&ele[i].weight!=ele[j].weight)
        {
            for(k=0;k<sofar[i];k++)
                ary[j][k]=ary[i][k];
            ary[j][k]=j;
            sofar[j]=sofar[i]+1;
            if(sofar[j]>max)
            {
                max=sofar[j];
                max_i=j;
            }
        }
    }
    printf("%d\n",max);
    for(i=0;i<max;i++)
        printf("%d\n",ele[ary[max_i][i]].index);
    return 0;
}
