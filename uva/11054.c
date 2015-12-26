#include <stdio.h>
int main()
{
    long long int total_cost,i,j,n,resident[100001];
    while(scanf("%lld",&n)&&n)
    {
        for(i=0;i<n;i++)
        scanf("%lld",&resident[i]);
        total_cost=0;
        for(i=0;i<n;i++)
        {
            if(resident[i]>0)
            for(j=i+1;resident[i]>0;j++)
            {
                if(resident[j]<0)
                {
                    if(resident[j]*-1>resident[i])
                    {
                        total_cost+=(j-i)*resident[i];
                        resident[j]+=resident[i];
                        resident[i]=0;
                        break;
                    }
                    else
                    {
                        total_cost+=(j-i)*-resident[j];
                        resident[i]+=resident[j];
                        resident[j]=0;
                    }
                }
            }
            else if(resident[i]<0)
            for(j=i+1;resident[i]<0;j++)
            {
                if(resident[j]>0)
                {
                    if(resident[i]*-1>resident[j])
                    {
                        total_cost+=(j-i)*resident[j];
                        resident[i]+=resident[j];
                        resident[j]=0;
                    }
                    else
                    {
                        total_cost+=(j-i)*-resident[i];
                        resident[j]+=resident[i];
                        resident[i]=0;
                        break;
                    }
                }
            }
        }
        printf("%lld\n",total_cost);
    }
    return 0;
}
