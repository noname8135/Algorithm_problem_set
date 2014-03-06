#include <stdio.h>
#include <string.h>
int compare(char excuse_word[],char keyword[][50],int kw_count)
{
    int i,counter=0;
    for(i=0;i<kw_count;i++)
    {
        if(strcmp(keyword[i],excuse_word)==0)
        counter++;
    }
    return counter;
}
int main()
{
    int set_count=0,i,j,k,kw_count,ec_count,incident_count[20],max;
    char keyword[25][50],excuse[25][500],temp[50];
    while(scanf("%d %d",&kw_count,&ec_count)!=EOF)
    {
        printf("Excuse Set #%d\n",++set_count);
        memset(incident_count,0,sizeof(incident_count));max=0;
        for(i=0;i<kw_count;i++)
        scanf("%s",keyword[i]);
        scanf("\n");
        for(i=0;i<ec_count;i++)
        fgets(excuse[i],500,stdin);
        for(i=0;i<ec_count;i++)
        {
            for(j=0,k=0;excuse[i][j]!='\0';j++)
            {
                if(excuse[i][j]>='A'&&excuse[i][j]<='Z')
                temp[k++]=excuse[i][j]+' ';
                else if(excuse[i][j]>='a'&&excuse[i][j]<='z')
                temp[k++]=excuse[i][j];
                else if(k!=0)
                {
                    temp[k]='\0';
                    k=0;
                    incident_count[i]+=compare(temp,keyword,kw_count);
                }
            }
        }
        for(i=0;i<ec_count;i++)
        if(max<incident_count[i])
        max=incident_count[i];
        for(i=0;i<ec_count;i++)
        if(incident_count[i]==max)
        printf("%s",excuse[i]);
        printf("\n");
    }
    return 0;
}
