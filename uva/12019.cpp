#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

struct SET{
	vector <int> a;
	vector <SET> b; 
};

int main(){
	int n, instr_count;
	string instuction;
	stack <SET> S;
	SET tmp1,tmp2;d

	cin >> n;
	while(n--){
		S.clear();
		cin >> instr_count;
		while(instr_count--){
			cin >> instruction;
			cout << instruction;
			if(instruction == "PUSH"){
				tmp1.a.insert(1);
				//assert(empty(tmp1.b));
				S.push();
				cout << S.top().size() << endl;
			}
			else if(instruction == "DUP"){
				;
			}
			else if(instruction == "ADD"){
				;
			}
			else if(instruction == "UNION"){
				;
			}
			else if(instruction == "INTERSECT"){
				;
			}
		}
	}
	return 0;
}