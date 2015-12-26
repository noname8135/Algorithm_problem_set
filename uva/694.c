#include <stdio.h>

int main()
{
    long int A,L;
    int counter,case_count=0;
    while(scanf("%ld%ld",&A,&L))
    {
        if(A<0&&L<0)
        return 0;
        counter=1;case_count++;
        printf("Case %d: A = %d, limit = %d, number of terms = ",case_count,A,L);
        while(A!=1)
        {
            if(A%2)
            {
                A=A*3+1;
                if(A>L)
                break;
                else
                counter++;
            }
            else
            {A/=2;counter++;}
        }
        printf("%d\n",counter);
    }
    return 0;
}
