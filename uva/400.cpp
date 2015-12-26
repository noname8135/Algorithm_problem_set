#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
	for(int i=0;i<a.size() || i<b.size();i++)
		if(a[i] != b[i])
			return a[i] < b[i];
	return false;
}
int main(){
	int n,i,max_len,col_num,row_num,j,space_count;
	string files[100];
	while(cin >> n){
		cout << "------------------------------------------------------------\n";
		max_len = 0;
		for(i=0;i<n;i++){
			cin >> files[i];
			if(files[i].size() > max_len)
				max_len = files[i].size();
		}
		col_num = (60-max_len) / (max_len+2) + 1;
		row_num = n/col_num;
		sort(files,files+n,cmp);
		if(n%col_num)
			row_num++;
		for(i=0;i<row_num;i++){
			for(j=i;j<n;j+=row_num){
				cout << files[j];
				space_count = max_len - files[j].size();

				if(j+row_num < n){
					cout << "  ";
					while(space_count--)
						cout << " ";
				}
				else
					cout << endl;
			}
		}
		
		
	}
	return 0;
}