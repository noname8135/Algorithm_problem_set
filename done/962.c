#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool* once;
    int i,j,n,m;
    int* visited;
    int taxi_counter=0,taxicab_num[5000];
    once=(bool*)malloc(sizeof(bool)*1000100000);
    visited=(int*)malloc(sizeof(int)*1000);
    memset(once,0,sizeof(bool)*1000100000);
    for(i=1;i<1000;i++)
    {
        for(j=1;j<1000;j++)
        {
            printf("i=%d j=%d once=%d\n",i,j,once[i*i*i+j*j*j]);
            if(i*i*i+j*j*j>1000100000)
                break;
            else if(!once[i*i*i+j*j*j])
                {
                    once[i*i*i+j*j*j]=true;
                    visited[i]=i*i*i+j*j*j;
                }
            else if(once[i*i*i+j*j*j]&&visited[j]!=i*i*i+j*j*j)
                {
                    taxicab_num[taxi_counter++]=i*i*i+j*j*j;
                    printf("yes");

                    printf("i= %d vist=%d\n",i,visited[j]);goto fuck;
                }
        }
    }
    fuck:
    while(scanf("%d%d",&n,&m)==2)
    {
        ;
    }
    return 0;
}
