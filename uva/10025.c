#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*example:
1+2+3+...+n -> the minimum
by the first time the minimum keep -2
reaches $num, the n is the answer
*/
int main()
{
    int n,num,total,i;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&num);
        if(num<0)
        num*=-1;
        for(i=1,total=1;;i++,total+=i)
        {
            if(num==0)
            {printf("3\n");break;}
            if(total<num)
            continue;
            else if((total-num)%2==0)
            {printf("%d\n",i);break;}
        }
        if(n)
        printf("\n");
    }
    return 0;
}
