#include <iostream>

using namespace std;

int* next_ary(int* a, int n){
	int* ret = new int[n];
	for(int i=0;i<n-1;i++)
		ret[i] = a[i+1] - a[i]>0 ? a[i+1] - a[i] : a[i]-a[i+1];
	ret[n-1] = a[n-1] - a[0] > 0 ? a[n-1] - a[0] : a[0] - a[n-1];
	return ret;
}

bool is_all_zero(int* a, int n){
	for(int i=0;i<n;i++)
		if(a[i] != 0)
			return false;
	return true;
}

int main(){
	int ary_size, case_count, counter, i;
	int* ary;
	bool loop;
	cin >> case_count;
	while(case_count--){
		cin >> ary_size;
		ary = new int [ary_size];
		for(i=0;i<ary_size;i++)
			cin >> ary[i];
		counter = 1000;
		loop = true;
		while(counter-- && loop){
			if(is_all_zero(ary,ary_size))
				loop = false;
			ary = next_ary(ary,ary_size);
		}
		if(loop)
			cout << "LOOP\n";
		else 
			cout << "ZERO\n";
		delete ary;
	}
	return 0;
}