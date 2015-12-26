#include <iostream> 
#include <math.h>
#include <string>

using namespace std;

class AB{

public:

	int max_possible(int a){
		if(a%2)
			return a*a/4;
		return a/2 * (a/2 + 1);
	}

	void swap(string a, int pos, int minus){
		//1 2 3 4 5 
		//  m   p
		//if pos = 3 and minus = 2
		int tmp;
		tmp = a[pos];
		a[pos] = a[pos-minus];
		a[pos-minus] = tmp;
		return;
	}

	string createString(int N, int K){
		AB_ary = string(N,'A');
		int min_len,a,b,i,accum;
		a = floor(sqrt(K));
		b = a+1;
		if(max_possible(N) < K){
			return "";
		}
		else if(K> a*b){
			min_len = 2*b;
			accum = b*b;
		}
		else{
			min_len = a+b;
			accum = a*b;
		}

		for(i=0;i<N - min_len;i++)
			AB_ary[i] = 'B';
		for(i=N-1;i>N-b-1;i--)
			AB_ary[i] = 'B';
		AB_ary[N] = '\0';
		
		if(accum-K)
			swap(AB_ary,i+1,accum-K);
		return  AB_ary;
	}

private:
	string AB_ary;
};



int main(){
	AB test;
	int N,K,min_len,a,b,i,accum;	
	cin >> N >> K;
	cout << test.createString(N,K);
	return 0;
}

/*
BBBB  AAABBB
K = 8
a= 2
b= 3
acc = 9

You are given two s: N and K. Lun the dog is interested in strings that satisfy the following conditions:

    The string has exactly N characters, each of which is either 'A' or 'B'.
    The string s has exactly K pairs (i, j) (0 <= i < j <= N-1) such that s[i] = 'A' and s[j] = 'B'.

If there exists a string that satisfies the conditions, find and return any such string. Otherwise, return an empty string.
1)
2
0
Returns: "BA"
Please note that there are valid test cases with K = 0.
2)
5
8
Returns: ""
Five characters is too short for this value of K.
*/