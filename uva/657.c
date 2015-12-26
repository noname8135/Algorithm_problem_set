#include <stdio.h>
void markvisit(char graph[][51],int x,int y,int width,int height,int visited[][51])
{
	if(graph[y][x]!='X'||x<0||x>=width||y<0||y>=height)
		return;
	graph[y][x]='*';
	markvisit(graph,x-1,y,width,height,visited);
	markvisit(graph,x+1,y,width,height,visited);
	markvisit(graph,x,y-1,width,height,visited);
	markvisit(graph,x,y+1,width,height,visited);
	return ;
}
void count_point(char graph[][51],int x,int y,int width,int height,int visited[][51],int* point)
{
	if((graph[y][x]!='*'&&graph[y][x]!='X')||x<0||x>=width||y<0||y>=height||visited[y][x])
		return ;
	visited[y][x]=1;
	if(graph[y][x]=='X')
		{
			(*point)++;
			markvisit(graph,x,y,width,height,visited);
		}
	count_point(graph,x-1,y,width,height,visited,point);
	count_point(graph,x+1,y,width,height,visited,point);
	count_point(graph,x,y-1,width,height,visited,point);
	count_point(graph,x,y+1,width,height,visited,point);
	return ;
}
int main()
{
	int tmp,width,height,i,j,visited[51][51],die_count,die_point[100],throw_count=0,point;
	char graph[51][51],line[60];
	while(scanf("%d%d\n",&width,&height)&&width&&height)
	{
		die_count=0;
		for(i=0;i<height;i++)
			{
				fgets(line,55,stdin);
				for(j=0;j<width;j++)
				{
					visited[i][j]=0;
					sscanf(line+j,"%c",&graph[i][j]);
				}
			}
		for(i=0;i<height;i++)
			{
				for(j=0;j<width;j++)
				{
					if(!visited[i][j]&&(graph[i][j]=='*'||graph[i][j]=='X'))
					{
						point=0;
						count_point(graph,j,i,width,height,visited,&point);
						if(point)
						die_point[die_count++]=point;
					}
					else if(!visited[i][j])
						visited[i][j]=1;
				}
			}
		for(i=0;i<die_count-1;i++)
			for(j=i+1;j<die_count;j++)
				if(die_point[i]>die_point[j])
				{
					tmp=die_point[i];
					die_point[i]=die_point[j];
					die_point[j]=tmp;
				}
		printf("Throw %d\n",++throw_count);
		for(i=0;i<die_count;i++)
			{
				printf("%d",die_point[i]);
				if(i==die_count-1)
					printf("\n\n");
				else
					printf(" ");
			}
	}
	return 0;
}