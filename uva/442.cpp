#include <iostream>
#include <stack> 
#include <string>

using namespace std;
struct Matrix{
	int r,c;
};

int get_mul_count(Matrix a, Matrix b){
	if(a.c != b.r)
		return -1;
	return a.r * a.c * b.c;
}

int main(){
	stack<Matrix> syntax;
	Matrix M[26],a,b;
	string tmp;
	char label,walker;
	int i,tmp_r,tmp_c,maxtrix_num; // row, col
	long long int mul, mul_tmp;
	cin >> maxtrix_num;
	while(maxtrix_num--){
		cin >> label >> tmp_r >> tmp_c;
		M[label-'A'].r = tmp_r, M[label-'A'].c = tmp_c;
	}
	while(cin >> tmp){
		mul = 0;
		for(i=0;i<tmp.size();i++){
			if(tmp[i] ==')'){	//pull two when ) is met
				a=syntax.top(), syntax.pop();
				b=syntax.top(), syntax.pop();
				mul_tmp = get_mul_count(b,a);
				if(mul_tmp == -1){
					cout << "error" << endl ;
					break;
				}
				mul += mul_tmp;
				b.c = a.c;
				syntax.push(b);	//and push the result back
			}
			else if(tmp[i]>='A' && tmp[i]<='Z')
				syntax.push(M[tmp[i]-'A']);
		}
		if(mul_tmp!=-1)
			cout << mul << endl;
	}
	return 0;
}