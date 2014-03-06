#include <stdio.h>
#include <stdlib.h>

int goal;
void NODE(char* str,int sum,int* flag)
{
    char tmp,for_num[20];
    int num,count=0;
    if(str[0]=='\0'||*flag==1)
        return ;
    else if(str[0]=='-')
        count++;
    int i=0;
    while(str[count]>='0'&&str[count]<='9')
        {
            for_num[i]=str[count];
            count++;i++;
        }
    for_num[i]='\0';
    num=atoi(for_num);
    if(str[0]=='-')
        num=num*-1;
    if(str[count]=='('&&str[count+1]==')'&&str[count+2]=='('&&str[count+3]==')')
    {
        if(sum+num==goal)
            *flag=1;
        return ;
    }
    if(str[count]!='('||str[count+1]!=')')
    NODE(str+count+1,sum+num,flag);
    count++;
    int left=1,right=0;
    while(left!=right)
    {
        if(str[count]=='(')
            left++;
        else if(str[count]==')')
            right++;
        count++;
    }
    if(str[count]!='('||str[count+1]!=')')
    NODE(str+count+1,sum+num,flag);
    return;
}
int main()
{
    int tree_count,flag,first=1;
    char tree_str[10000],tmp;
    while(scanf("%d",&goal)!=EOF)
    {
        tmp='\0';
        while(tmp!='(')
        {
            scanf("%c",&tmp);
        }
        int left=1,right=0;
        tree_count=0;
        while(left!=right)
        {
            scanf("%c",&tmp);
            if(tmp=='(')
                left++;
            else if(tmp==')')
                right++;
            if(tmp!=' '&&tmp!='\n')
                tree_str[tree_count++]=tmp;
        }
        tree_str[tree_count-1]='\0';
        flag=0;
        NODE(tree_str,0,&flag);


        if(tree_str[0]=='\0')
            printf("no\n");
        else if(flag)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
