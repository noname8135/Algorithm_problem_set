#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
//maze exploration!

void dfs_paint(char maze[][82],int x,int y){
	if(maze[y][x]!=' ')
		return;
	maze[y][x] = '#';
	dfs_paint(maze,x+1,y);
	dfs_paint(maze,x-1,y);
	dfs_paint(maze,x,y+1);
	dfs_paint(maze,x,y-1);
	return ;
}
int main(){
	char maze[30][82];
	char output_separate[82];
	int line_count,n,i,start_x,start_y;
	cin >> n;
	while(n--){
		line_count = 0;
		while(fgets(maze[line_count],82,stdin)){
			if(maze[line_count][0] == '_'){
				strcpy(output_separate,maze[line_count]);
				break;
			}
			else if(maze[line_count][0] == '\n')
				continue;
			for(i=0;i<strlen(maze[line_count]);i++){
				if(maze[line_count][i] == '*'){
					start_x = i, start_y = line_count;
					maze[line_count][i] = ' ';
				}
			}
			line_count++;
		}
		dfs_paint(maze,start_x,start_y);
		for(i=0;i<line_count;i++)
			fputs(maze[i],stdout);
		cout<<output_separate;
	}
	return 0;
}