#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int cmp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n,i,j,m,dup_flag,k;
    int phone[500000];
    int dup_count;
    char temp;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        memset(phone,0,sizeof(int)*m);
        i=0;j=0;k=1000000;
        while(scanf("%c",&temp))
        {
            if(temp=='-'||temp=='\n')
            continue;
            switch(temp)
            {case 'A':
            case 'B':
            case 'C':
            phone[i]+=2*k;k/=10;break;
            case 'D':
            case 'E':
            case 'F':
            phone[i]+=3*k;k/=10;break;
            case 'G':
            case 'H':
            case 'I':
            phone[i]+=4*k;k/=10;break;
            case 'J':
            case 'K':
            case 'L':
            phone[i]+=5*k;k/=10;break;
            case 'M':
            case 'N':
            case 'O':
            phone[i]+=6*k;k/=10;break;
            case 'P':
            case 'R':
            case 'S':
            phone[i]+=7*k;k/=10;break;
            case 'T':
            case 'U':
            case 'V':
            phone[i]+=8*k;k/=10;break;
            case 'W':
            case 'X':
            case 'Y':
            phone[i]+=9*k;k/=10;break;
            case '0'...'9':
            phone[i]+=(temp-'0')*k;k/=10;
            }
            j++;
            if(j==7)
            {i++;j=0;k=1000000;}
            if(i==m)
            break;
        }
        qsort(phone,m,sizeof(int),cmp);
        for(i=1,dup_flag=0,dup_count=1;i<m;i++)
        {
            if(phone[i]==phone[i-1])
            {dup_count++;dup_flag=1;}
            else if(dup_count!=1)
            {printf("%03d-%04d %4d\n",phone[i-1]/10000,phone[i-1]%10000,dup_count);dup_count=1;}
        }
        if(!dup_flag)
        printf("No duplicates.\n");
        printf("\n");
    }
    return 0;
}
