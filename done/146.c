#include <stdio.h>
#include <string.h>
int main()
{
    int appear_count[27],i,judge_index,j,found_index,k,stop_index;
    char str[51];
    while(scanf("%s",str)!=EOF)
    {
        memset(appear_count,0,sizeof(int)*27);
        if(str[0]=='#')
            break;
        for(i=0;i<strlen(str);i++)
            appear_count[str[i]-'a']++;
        found_index=-1;
        for(stop_index=strlen(str)-1;stop_index>=0;stop_index--)
        {
            for(judge_index=strlen(str)-1;judge_index>stop_index;judge_index--)  //start from the back to the head of string
            for(i=judge_index-1;i>=stop_index;i--)   //find the first smaller one
            {

                if(str[judge_index]>str[i])
                    {
                        found_index=i;
                        appear_count[str[judge_index]-'a']--;
                        for(j=found_index-1;j>=0;j--)   //replace that one by judge_index's value and reset all the char after it alphabetically
                            appear_count[str[j]-'a']--;
                        str[found_index]=str[judge_index];
                        for(j=found_index+1,k=0;k<26;k++)
                            while(appear_count[k]!=0)
                                {
                                    appear_count[k]--;
                                    str[j++]=k+'a';
                                }
                        goto done;
                    }
            }
        }
        done:
        if(stop_index==-1)
            printf("No Successor\n");
        else
            printf("%s\n",str);
    }
    return 0;
}
