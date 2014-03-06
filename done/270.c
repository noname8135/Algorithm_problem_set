#include <stdio.h>
#include <stdlib.h>

typedef struct fdsgfdg
{
    int x,y;
}COORD;

typedef struct Ssfsg{
    int rate_x,rate_y,x,y;
}SLOPE;

int main()
{
    SLOPE* slope;
    COORD coord[800];
    slope=(SLOPE*)malloc(sizeof(slope[0])*300000);
    char tmp[100];
    int t,slope_count,coord_num,i,RX,RY,j,max,count;
    scanf("%d\n\n",&t);
    while(t--)
    {
        coord_num=0,slope_count=0,max=0;
        while(fgets(tmp,99,stdin))
        {
            if (tmp[0]=='\n')
            break;
            sscanf(tmp,"%d %d",&(coord[coord_num].x),&(coord[coord_num].y));
            for(i=0;i<coord_num;i++)
            {
                slope[slope_count].rate_x=coord[coord_num].x-coord[i].x;
                slope[slope_count].rate_y=coord[coord_num].y-coord[i].y;
                slope[slope_count].x=coord[i].x;
                slope[slope_count++].y=coord[i].y;
            }
            coord_num++;
        }
        max=0;
        for(i=0;i<slope_count;i++)
        {
            count=0;
            for(j=0;j<coord_num;j++)
            if((coord[j].x-slope[i].x)*slope[i].rate_y==(coord[j].y-slope[i].y)*slope[i].rate_x)
            count++;
            if(count>max)
            max=count;
        }
        printf("%d\n",max);
        if(t)
            printf("\n");
    }
    return 0;
}
