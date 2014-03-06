#include <stdio.h>
#include <stdlib.h>
void push_Q(int* ary,int a,int* count)
{
    int walker=*count;
    while(walker)
    {
        if(ary[(walker-1)/2]>a)
            ary[walker]=ary[(walker-1)/2];
        else
        break;
        walker=(walker-1)/2;
    }
    ary[walker]=a;
    (*count)++;
    return ;
}
void pop_Q(int* ary,int* count)
{
    int walker=0,tmp;
    ary[0]=ary[--(*count)];
    while(walker*2+1<*count)
    {
        if(walker*2+2>=*count&&ary[walker*2+1]<ary[walker])
            tmp=walker*2+1;
        else if(ary[walker*2+1]<ary[walker]||ary[walker*2+2]<ary[walker])
            tmp=ary[walker*2+1]<ary[walker*2+2]?walker*2+1:walker*2+2;
        else
        break;
        ary[walker]=ary[tmp];
        walker=tmp;
    }
    ary[walker]=ary[*count];
    return ;
}
int diff(int* ary,int count)
{
    if(count==1)
        return 2147483647;
    else if(count==2)
        return ary[1]-ary[0];
    else
        return ary[1]-ary[0]>ary[2]-ary[0]?ary[2]-ary[0]:ary[1]-ary[0];
}
int main()
{
    int **num,q_count[800]={0},n,tmp,i,j,next_index,min_diff,sum,difference[800];
    char junk;
    num=(int**)malloc(sizeof(int*)*800);
    for(i=0;i<800;i++)
        num[i]=(int*)malloc(sizeof(int)*800);
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&tmp);
            push_Q(num[i],tmp,q_count+i);
        }
        sum=0; min_diff=2147483647;
        for(i=0;i<n;i++)
        {
            sum+=num[i][0];
            difference[i]=diff(num[i],q_count[i]);
            if(difference[i]<min_diff)
                {
                    next_index=i;
                    min_diff=difference[i];
                }
        }
        printf("%d",sum);
        sum-=num[next_index][0];
        pop_Q(num[next_index],q_count+next_index);
        difference[next_index]=diff(num[next_index],q_count[next_index]);
        sum+=num[next_index][0];

    for(j=0;j<n;j++)
        {
            min_diff=2147483647;
            for(i=0;i<n;i++)
            {
                if(difference[i]<min_diff)
                {
                    next_index=i;
                    min_diff=difference[i];
                }
            }
            if(j!=n-1)
            printf(" %d",sum);
            else
            printf(" %d\n",sum);
            sum-=num[next_index][0];
            pop_Q(num[next_index],q_count+next_index);
            difference[next_index]=diff(num[next_index],q_count[next_index]);
            sum+=num[next_index][0];
        }
    }
    return 0;
}
