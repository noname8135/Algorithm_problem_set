#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){	
	
	string cmd;
	int n,m,i,tmp,cur_team,case_count=0;
	int* which_team;
	int member_count[1000]; //count current member number in each team queue
	which_team = new int [10000000];
	while(cin >> n){
		if(!n)
			break;
		case_count ++ ;
		cout << "Scenario #"<<case_count << endl;
		queue <int> team_order;
		queue <int> team[1000];
		for(i=0;i<n;i++){
			cin >> m;
			while(m--){
				cin >> tmp;
				which_team[tmp] = i;
			}
		}
		while(cin >> cmd && cmd != "STOP"){
			if(cmd == "ENQUEUE"){
				cin >> tmp;
				cur_team = which_team[tmp];
				if(team[cur_team].size() == 0)
					team_order.push(cur_team);
				team[cur_team].push(tmp);
			}
			else if(cmd == "DEQUEUE"){
				cur_team = team_order.front();
				cout << team[cur_team].front()<< endl;
				team[cur_team].pop();
				if(team[cur_team].size() == 0)
					team_order.pop();
			}
		}
		cout << endl;
	}
	return 0;
};