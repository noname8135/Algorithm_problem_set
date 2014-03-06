#include <stdio.h>
#include <stdlib.h>
typedef struct Ujbdsjk{
    int str[10];
    int ori_index;
}STR;
int cmp(const void* a,const void* b)
{
    return *((int*)a)-*((int*)b);
}
int a_in_b(int* a,int* b,int n)
{
    int i;
    for(i=0;i<n;i++)
        if(a[i]>=b[i])
        return 0;
    return 1;
}
int dimen;
int cmp2(const void* a,const void* b)
{
    return (*((STR*)a)).str[0]-(*((STR*)b)).str[0];
}

int main()
{
    int first=1;
    STR item[1000];
    int j,n,k,i,max,nest_count[1000],ans[1000][30],max_index;
    while(scanf("%d%d",&n,&dimen)==2)
    {
        for(i=0;i<n;i++)
        {
            nest_count[i]=1;
            for(j=0;j<dimen;j++)
            {
                scanf("%d",&(item[i].str[j]));
            }
            item[i].ori_index=i+1;
            qsort(item[i].str,dimen,sizeof(int),cmp);
        }
        qsort(item,n,sizeof(item[0]),cmp2);

        for(i=0;i<n;i++)
            ans[i][0]=item[i].ori_index;
        max=1;max_index=0;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(nest_count[i]+1>nest_count[j]&&a_in_b(item[i].str,item[j].str,dimen))
                {
                    nest_count[j]=nest_count[i]+1;
                    for(k=0;k<nest_count[i];k++)
                        ans[j][k]=ans[i][k];
                    ans[j][k]=item[j].ori_index;
                    if(nest_count[max_index]<nest_count[j])
                    max_index=j;
                }
            }
        }
        printf("%d\n",nest_count[max_index]);
        for(i=0;i<nest_count[max_index];i++)
        {
            if(i!=nest_count[max_index]-1)
                printf("%d ",ans[max_index][i]);
            else
                printf("%d\n",ans[max_index][i]);
        }
    }
    return 0;
}
