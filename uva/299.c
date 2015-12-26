#include <stdio.h>

int main()
{
    int test_case,n,i,carriage[51],counter,temp;
    scanf("%d",&test_case);
    while(test_case--)
    {
        scanf("%d",&n);
        counter=0;
        for(i=0;i<n;i++)
        scanf("%d",&carriage[i]);
        while(n>1)
        {for(i=1;i<n;i++)
        if(carriage[i-1]>carriage[i])
        {
            temp=carriage[i-1];
            carriage[i-1]=carriage[i];
            carriage[i]=temp;
            counter++;
        }
        n--;
        }
        printf("Optimal train swapping takes %d swaps.\n",counter);
    }
}
