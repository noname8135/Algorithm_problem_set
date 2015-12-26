#include <iostream>
#include <algorithm>
using namespace std;

struct coordinate{
	float x,y;
};

bool cmp(coordinate a, coordinate b){
	return a.x < b.x;
}

bool check_symetric(coordinate* dot,int dot_count,float mid_x){
	int i,j;
	bool found;
	for(i=0;i<dot_count/2;i++){
		if(dot[i].x < mid_x){
			for(j=i/2;j<dot_count;j++)
				if(dot[j].y == dot[i].y && dot[j].x-mid_x == mid_x - dot[i].x)
					break;
			if(j == dot_count)
				return false;
		}
		else if(dot[i].x > mid_x){
			for(j=0;j<dot_count/2;j++)
				if(dot[j].y == dot[i].y && dot[i].x-mid_x == mid_x - dot[j].x)
					break;
			if(j == dot_count/2)
				return false;
		}
	}
	return true;
}

int main(){
	int n, dot_count,i ;
	float mid;
	coordinate dot[1000];
	cin >> n;
	while(n--){
		cin >> dot_count;
		for(i=0;i<dot_count;i++)
			cin >>dot[i].x >> dot[i].y;
		sort(dot,dot+dot_count,cmp);
		mid = dot_count%2 ? dot[dot_count/2].x : (dot[dot_count/2].x + dot[dot_count/2-1].x) / 2;
		if(check_symetric(dot,dot_count,mid))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}