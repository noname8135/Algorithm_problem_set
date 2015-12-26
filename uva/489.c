#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int cmp(const void* a,const void* b)
{
    return (*((char*)a)-*((char*)b));
}
int main()
{
    bool judged[270],find;
    int j,i,case_count,ans_word_count,guess_count,death_count;
    char ans[1000],guess[1000];
    while(scanf("%d",&case_count))
    {
        if(case_count==-1)
        return 0;
        printf("Round %d\n",case_count);
        scanf("%s",ans);
        ans_word_count=0;guess_count=0;death_count=0;
        memset(judged,0,sizeof(judged));
        qsort(ans,strlen(ans),sizeof(char),cmp);
        for(i=0;ans[i]!='\0';i++)
        if(ans[i]==ans[i+1])
        {
            j=i+1;
            while(ans[i]==ans[j])
            {ans[j]='-';j++;}
            i=j-1;
        }
        for(i=0;ans[i]!='\0';i++)
        if(ans[i]!='-')
        ans_word_count++;
        scanf("%s",guess);
        for(i=0;guess[i]!='\0'&&death_count!=7&&ans_word_count!=guess_count;i++)
        {
            if(judged[guess[i]])
            continue;
            for(j=0,find=0;ans[j]!='\0';j++)
            {
            if(ans[j]=='-')
            continue;
            else if(guess[i]==ans[j]&&!judged[guess[i]])
            {
                guess_count++;
                find=1;
                break;
            }
            }
            judged[guess[i]]=1;
            if(!find)
            death_count++;
        }
        if(ans_word_count==guess_count)
        printf("You win.\n");
        else if(death_count==7)
        printf("You lose.\n");
        else
        printf("You chickened out.\n");
    }
    return 0;
}
