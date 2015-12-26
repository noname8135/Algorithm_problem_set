#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main(){
    int u[1500], p[3]={2,3,5};
    int i, j, k;
    u[0]=1;u[1]=2;u[2]=3;
    for(i=3;i<1500;i++)
    {
        u[i]=INT_MAX;
        for(j=0;j<3;j++)
        {for(k=0;p[j]*u[k]<=u[i-1];k++);
        if(u[i]>p[j]*u[k])
        u[i]=p[j]*u[k];}
    }
    printf("The 1500'th ugly number is %d.\n", u[1499]);
    return 0;
}
