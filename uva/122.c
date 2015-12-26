#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct NODE{
    struct NODE *left;
    struct NODE *right;
    bool used;
    int value;
}Node;
void check_taken(Node* walker,bool* error)
{
    if(walker==NULL)
        return;
    else if(walker->used==0)
    {
        *error=1;
        return ;
    }
    check_taken(walker->left,error);
    check_taken(walker->right,error);
    return ;
}
void prin(Node* walker)
{
    if(walker==NULL)
        return;
    printf("%d ",walker->value);
    prin(walker->left);
    prin(walker->right);
    return ;
}
int main()
{
    int i,tmp_value,q_count,q_now;
    char tmp[100],place[100];
    Node* root,*walker,*q[1000];
    root=(Node*)malloc(sizeof(Node));
    root->left=NULL;
    root->right=NULL;
    root->used=0;
    bool error=0;
    while(scanf("%s",tmp)!=EOF)
    {
        if(tmp[0]=='('&&tmp[1]==')')
        {
            check_taken(root,&error);
            if(error)
                printf("not complete\n");
            else
                {
                    q_count=0;q_now=0;
                    printf("%d",root->value);
                    if(root->left!=NULL)
                    q[q_count++]=root->left;
                    if(root->right!=NULL)
                    q[q_count++]=root->right;
                    while(q_now!=q_count)
                    {
                        walker=q[q_now];
                        printf(" %d",walker->value);
                        q_now++;
                        if(walker->left!=NULL)
                        q[q_count++]=walker->left;
                        if(walker->right!=NULL)
                        q[q_count++]=walker->right;
                    }
                    printf("\n");
                }
            error=0;free(root);
            root=(Node*)malloc(sizeof(Node));
            root->left=NULL;
            root->right=NULL;
            root->used=0;
        }
        else
        {
            sscanf(tmp+1,"%d",&tmp_value);
            i=1;
            //printf("value=%d ",tmp_value);
            while(tmp[i]!=',')
                i++;
            sscanf(tmp+i+1,"%s",place);
            for(i=0,walker=root;place[i]!=')';i++)
            {
                if(place[i]=='R')
                {
                    if(walker->right==NULL)
                    {
                        walker->right=(Node*)malloc(sizeof(Node));
                        walker->right->left=NULL;
                        walker->right->right=NULL;
                        walker->right->used=0;
                    }
                    walker=walker->right;
                }
                else
                {
                    if(walker->left==NULL)
                    {
                        walker->left=(Node*)malloc(sizeof(Node));
                        walker->left->left=NULL;
                        walker->left->right=NULL;
                        walker->left->used=0;
                    }
                    walker=walker->left;
                }
            }
            if(walker->used)
                error=1;
            walker->value=tmp_value;
            walker->used=1;
        }
    }
    return 0;
}
