#include <iostream>

using namespace std;

int next_carry(int n,int base){
	return n/base;
}
int lsd(int n, int base){
	return n%base;
}

int get_ans(int base, int a, int b){
	int carry=0,digit_count=0,prev_a,target=a;
	while(1){
		prev_a = a;
		a = lsd(carry+a*b,base);
		++digit_count;
		carry = next_carry(carry+prev_a*b,base);
		if(a == target && carry == 0)
			break;
	}
	return digit_count;
}

int main(){
	int base,a,b;	//a = rightmost digit of first factor, b = second factor
	int num[1000]; 	//repre
	while(scanf("%d %d %d",&base,&a,&b)!=EOF){
		cout << get_ans(base,a,b) << endl;
	}
	return 0;
}