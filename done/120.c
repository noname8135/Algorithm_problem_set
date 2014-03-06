#include <stdio.h>
#include <string.h>
//flip the max to most left, and flip(n-1) to transfer it to most right
void flip(int stack[],int ins_location)
{
    int temp,i;
    for(i=0;i<=ins_location/2;i++)
    {
        temp=stack[i];
        stack[i]=stack[ins_location-i];
        stack[ins_location-i]=temp;
    }
    return ;
}
void max_to_left(int stack[],int total,int wall)
{
    if(wall<=1)
    {printf("0\n");
    return ;}
    int i,max=0,max_index;
    for(i=0;i<wall;i++)
    if(stack[i]>max)
    {max_index=i;max=stack[i];}
    //printf("max_index=%d total=%d\n",max_index,total);
    if(max_index==wall-1)
    {//printf("byebye~~\n");
    return max_to_left(stack,total,wall-1);}
    else if(max_index!=0)
    {flip(stack,max_index);
    printf("%d ",total-max_index);}
    flip(stack,wall-1);
    printf("%d ",total-wall+1);
    return max_to_left(stack,total,wall-1);
}
int main()
{
    char tmp[200];
    int stack[40],walker,i,total;
    while(fgets(tmp,200,stdin)!=NULL)
    {
        walker=0;i=0;
        while(walker<strlen(tmp))
        {
            sscanf(tmp+walker,"%d",&stack[i++]);
            if(stack[i-1]<10)
            walker+=2;
            else if(stack[i-1]<100)
            walker+=3;
            else
            walker+=4;
        }
        total=i;
        for(i=0;i<total;i++)
        if(i==total-1)
        printf("%d\n",stack[i]);
        else
        printf("%d ",stack[i]);
        max_to_left(stack,total,total);
    }
    return 0;
}
