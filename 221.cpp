#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct BUILDING{
	int x,y,width,height,id;
};

bool cmp(BUILDING a, BUILDING b){
	if(a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

bool visible(BUILDING a, set <int> all_x, int n, BUILDING building[100]){
	set <int>::iterator it;
	int up_bound = a.x+a.width,i;
	for(it=all_x.begin();it!=all_x.end();it++){	//if the building is visible at any of the segment
		if(*it+1>a.x && *it+1<up_bound){
			for(i=0;i<n;i++){	//see if any other bulding is blocking
				if(*it+1>building[i].x && *it+1<building[i].x+building[i].width && building[i].y<a.y && building[i].height >= a.height)
					break;
			}
			if(i==n)	//not blocked by any other building
				return true;
		}
		else if(*it>=up_bound)
			break;
	}
	return false;
}

int main(){
	int n,map_count=0,walker,i;	//walker = rightmost x coordinate
	BUILDING building[100];
	set <int> all_x;
	
	while(cin>>n && n){
		++map_count;
		for(i=0;i<n;i++){
			cin >> building[i].x >> building[i].y >> building[i].width >> walker >> building[i].height;	//walker here is for useless parameter
			all_x.insert(building[i].x);	//all segment of x coordinate(sorted and uniqued)
			all_x.insert(building[i].x+building[i].width);
			building[i].id = i+1;
		}
		sort(building,building+n,cmp);
		if(map_count!=1)
			cout <<endl;
		cout << "For map #" << map_count<<", the visible buildings are numbered as follows:\n";
		cout << building[0].id;
		for(i=1;i<n;i++){
			if(visible(building[i],all_x,n,building))
				cout << " " << building[i].id;
		}
		all_x.clear();
		cout << endl;
	}
	return 0;
}