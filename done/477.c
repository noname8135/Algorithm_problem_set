#include <stdio.h>
#include <math.h>
typedef struct FIG
{
    char type;
    float c_x,c_y,c_r,r_x1,r_y1,r_x2,r_y2;
}FIGURE;
int main()
{
    FIGURE figure[20];
    float point_x,point_y;
    int i,fig_count=0,point_count=0,flag,j;
    char description;
    while(scanf("%c",&description))
    {
        if(description=='*')
        break;
        else if(description=='r')
        {
            figure[fig_count].type='r';
            scanf("%f%f%f%f\n",&figure[fig_count].r_x1,&figure[fig_count].r_y1,&figure[fig_count].r_x2,&figure[fig_count].r_y2);
            fig_count++;
        }
        else if(description=='c')
        {
            figure[fig_count].type='c';
            scanf("%f%f%f\n",&figure[fig_count].c_x,&figure[fig_count].c_y,&figure[fig_count].c_r);
            fig_count++;
        }
    }
    point_count=0;
    while(scanf("%f%f\n",&point_x,&point_y))
    {
        if((int)point_x==9999&&(int)point_y==9999)
        break;
        point_count++;
        flag=0;
        for(j=0;j<fig_count;j++)
        {
        if(figure[j].type=='r')
        {
            if(point_x>figure[j].r_x1&&point_x<figure[j].r_x2&&point_y<figure[j].r_y1&&point_y>figure[j].r_y2)
            {printf("Point %d is contained in figure %d\n",point_count,j+1);flag=1;}
        }
        else if(figure[j].type=='c')
        {
            if(sqrt((point_x-figure[j].c_x)*(point_x-figure[j].c_x)+(point_y-figure[j].c_y)*(point_y-figure[j].c_y))<figure[j].c_r)
            {printf("Point %d is contained in figure %d\n",point_count,j+1);flag=1;}
        }
        }
        if(!flag)
        {printf("Point %d is not contained in any figure\n",point_count);}
    }
    return 0;
}
