#include <stdio.h>
int cal(int num)
{
    int sum=0;
    while(num)
    {
        sum+=num%10;
        num/=10;
    }
    if(sum>=10)
        return cal(sum);
    return sum;
}
int main()
{
    int a_ans,b_ans,i,a,b;
    char name1[50],name2[50];
    while(fgets(name1,49,stdin))
    {
        fgets(name2,49,stdin);
        a=0;b=0;
        for(i=0;name1[i]!='\0';i++)
            if(name1[i]>='A'&&name1[i]<='Z')
            a+=name1[i]-'A'+1;
            else if(name1[i]>='a'&&name1[i]<='z')
            a+=name1[i]-'a'+1;
        a_ans=cal(a);
        for(i=0;name2[i]!='\0';i++)
            if(name2[i]>='A'&&name2[i]<='Z')
            b+=name2[i]-'A'+1;
            else if(name2[i]>='a'&&name2[i]<='z')
            b+=name2[i]-'a'+1;
        b_ans=cal(b);
        if(a_ans>b_ans)
        printf("%.2f %%\n",(float)b_ans/(float)a_ans*100);
        else
        printf("%.2f %%\n",(float)a_ans/(float)b_ans*100);
    }
    return 0;
}
