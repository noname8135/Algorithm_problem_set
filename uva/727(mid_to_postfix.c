#include <stdio.h>
int prior(char a)
{
    if(a=='*'||a=='/')
        return 2;
    else if(a=='(')
        return 0;
    return 1;
}
int main()
{
    char op[51],input[20];
    int tmp,n,op_count,i;
    scanf("%d\n\n",&n);
    while(n>0)
    {
        op_count=0;
        while(fgets(input,19,stdin))
        {
            /*printf("now in stack__");
            for(i=0;i<op_count;i++)
                printf("%c",op[i]);
            printf("__\n");*/
            if(input[0]=='\n')
            break;
            else if(input[0]>='0'&&input[0]<='9')
            {
                printf("%c",input[0]);
            }
            else if(input[0]==')')
            {
                for(i=op_count-1;op[i]!='(';i--)
                    printf("%c",op[i]);
                op_count=i;
            }
            else if(input[0]=='(')
            op[op_count++]=input[0];
            else
            {
                while(op_count&&prior(input[0])<=prior(op[op_count-1]))
                {
                    printf("%c",op[op_count-1]);
                    op_count--;
                }
                op[op_count++]=input[0];
            }
        }
        for(i=op_count-1;i>=0;i--)
            printf("%c",op[i]);
            printf("\n");
        n--;
        if(n)
            printf("\n");
    }
}
