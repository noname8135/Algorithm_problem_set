#include <iostream>
#include <map>

using namespace std;

struct FROM_TO{
	int from,to;
};

bool operator <(const FROM_TO& a, const FROM_TO& b){
	if(a.from != b.from)
		return a.from < b.from;
	else
		return a.to < b.to;
}

int main(){
	int n,i,tmp2;
	map <FROM_TO, int> tbp; 	//waiting to be pair
	int* from;
	FROM_TO tmp;
	while(cin >> n && n){
		for(i=0;i<n;i++){
			cin >> tmp.from >> tmp.to;
			if(tbp.count(tmp) ){
				if(--tbp[tmp] == 0){
					tbp.erase(tmp);
				}
			}
			else{
				tmp2 = tmp.from;
				tmp.from = tmp.to;
				tmp.to = tmp2;
				if(tbp.count(tmp))
					tbp[tmp]++;
				else
					tbp[tmp] = 1;
			}
		}
		if(!tbp.size())
			cout << "YES\n";
		else
			cout << "NO\n";
		tbp.clear();
	}
	return 0;
}