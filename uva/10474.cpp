#include <iostream>
#include <algorithm>

using namespace std;

int find(int* a, int b, int n){	//return found index
	int i;
	for(i=0;i<n;i++)
		if(a[i] == b)
			return i;
	return -1;
}
int main(){
	int N,Q,target,tmp,case_count=0,i;
	int marble[50000];
	while(cin>>N>>Q && N!=0 && Q!=0){
		case_count++;
		cout << "CASE# " << case_count<<":"<<endl;
		for(i=0;i<N;i++)
			cin >>marble[i];
		sort(marble,marble+N);
		while(Q--){
			cin >> target;
			cout << target;
			tmp = find(marble,target,N);
			if(tmp == -1)
				cout << " not found" << endl;
			else
				cout << " found at " << tmp+1 << endl;
		}
	}
	return 0;
}