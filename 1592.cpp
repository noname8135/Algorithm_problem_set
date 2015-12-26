#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cstdio>
#include <vector>
using namespace std;
struct pos{
	int r,c;
};

void if_match(map <string, vector<pos> > db, string data[][10],int n, int m,int& c1, int& c2, int& r1, int& r2){
	int i,j,k;
	string cur_str;
	vector <pos> tmp;
	for(i=0;i<m;i++){
		if(db[data[n][i]].size() > 1){
			for(j=0;j<db[data[n][i]].size();j++){
				if(db[data[n][i]][j].r == n)
					continue;
				else if(db[data[n][i]][j].c == i){
					c1=i, r1=db[data[n][i]][j].r, r2=n;
					for(k=i+1;k<m;k++){
						if(data[r1][k] == data[r2][k]){
							c2 = k;
							return ;
						}
					}
				}
			}
		}
	}
}

int main(){
	int n,m,i,j,delimiter,walker,r1,c1,r2,c2,col;
	map <string, vector<pos> > db;
	string cur_str;
	string data[10000][10];
	pos cur_pos;
	char tmp[100],junk[100];
	while(scanf("%d %d\n",&n,&m) == 2){
		c1 = c2 = -1; 
		for(i=0;i<n;i++){
			cur_pos.r = i;
			for(j=0;j<m;j++){
				cur_pos.c = j;
				if(j==m-1)
					scanf("%s",tmp);
				else
					scanf("%[^,]%[,]",tmp,junk);
				cur_str = string(tmp);
				if(c2 != -1 || n==1 || m==1)
					continue;
				data[i][j] = cur_str;
				db[cur_str].push_back(cur_pos);
			}
			getchar();
			if_match(db,data,i,m,c1,c2,r1,r2);
		}
		db.clear();
		if(c2 == -1)
			printf("YES\n");
		else{
			printf("NO\n%d %d\n%d %d\n",r1+1,r2+1,c1+1,c2+1);
		}
	}
	return 0;
}