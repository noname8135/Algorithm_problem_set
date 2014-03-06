#include <stdio.h>
#include <string.h>
int cmp(const void* a,const void* b)
{
    return strlen((char *)a)-strlen((char *)b);
}
int main()
{
    int walker,n,i,ans[300],len,total;
    char frag[300][300];
    scanf("%d\n",&n);
    while(n--)
    {
        i=0;
        while(fgets(frag[i],299,stdin)!=NULL)
        {
            len=strlen(frag[i]);
            if(frag[i][0]=='\n'&&frag[i][1]=='\0')
                break;
            else if(frag[i][len-1]=='\n')
            frag[i][len-1]='\0';
            i++;
        }
        total=i;
        qsort(frag,total,sizeof(*frag),cmp);
        for(i=0;i<total;i++)
            printf("%s\n",frag[i]);


    }
    return 0;
}
