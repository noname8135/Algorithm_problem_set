#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a,const void* b)
{
    return strcmp(*(char**)a,*(char**)b);
}
int found(char** grid,char* str,int wd_count)
{
    int i;
    for(i=0;i<wd_count;i++)
    if(!strcmp(grid[i],str))
    return 1;
    return 0;
}
int main()
{
    int s,walker,k,j,i,line_count,ig_count,kw_count,flag=0;
    char temp[50],**ignor,**title,**kw;
    ignor=(char**)malloc(sizeof(char*)*5000);
    kw=(char**)malloc(sizeof(char*)*5000);
    title=(char**)malloc(sizeof(char*)*250);
    for(i=0;i<250;i++)
    title[i]=(char*)malloc(sizeof(char)*1000);
    for(i=0;i<3100;i++)
    {
        ignor[i]=(char*)malloc(sizeof(char)*30);
        kw[i]=(char*)malloc(sizeof(char)*30);
    }
    ig_count=0;
    while(scanf("%s",ignor[ig_count])&&strcmp(ignor[ig_count++],"::"))
    ;
    scanf("\n");
    line_count=0;
    while(fgets(title[line_count++],200,stdin)!=NULL)
    ;
    line_count--;
    if(title[line_count-1][strlen(title[line_count-1])-1]!='\n')
    {title[line_count-1][strlen(title[line_count-1])]='\n';
    title[line_count-1][strlen(title[line_count-1])+1]='\0';}
    for(i=0;i<line_count;i++)
    for(j=0;title[i][j]!='\0';j++)
    if(title[i][j]>='A'&&title[i][j]<='Z')
    title[i][j]+=' ';
    for(i=0,kw_count=0,walker=0;i<line_count;i++,walker=0)
    while(title[i][walker]!='\n')
    {
        sscanf(title[i]+walker,"%s",temp);
        if(!found(ignor,temp,ig_count))
        {
            strcpy(kw[kw_count++],temp);
            strcpy(ignor[ig_count++],temp);
        }
        walker+=strlen(temp);
        while((title[i][walker]<'a'||title[i][walker]>'z')&&title[i][walker]!='\n')
        walker++;
    }
    /*for(i=0;i<ig_count;i++)
    printf("ignore=%s\n",ignor[i]);
    for(i=0;i<kw_count;i++)
    printf("keyword=%s\n",kw[i]);*/
    qsort(kw,kw_count,sizeof(kw[0]),cmp);
    for(s=0;s<kw_count;s++)
    for(i=0,walker=0;i<line_count;i++,walker=0)
    while(title[i][walker]!='\n')
    {
        sscanf(title[i]+walker,"%s",temp);
        if(!strcmp(kw[s],temp))
        {
            /*if(flag)
            printf("\n");
            else
            flag=1;*/
            for(j=0;j<walker;j++)
            printf("%c",title[i][j]);
            for(;title[i][j]!=' '&&title[i][j]!='\n';j++)
            printf("%c",title[i][j]-' ');
            for(;title[i][j]!='\n';j++)
            printf("%c",title[i][j]);
            printf("\n");
        }
        walker+=strlen(temp);
        while((title[i][walker]<'a'||title[i][walker]>'z')&&title[i][walker]!='\n')
        walker++;
    }
    return 0;
}
