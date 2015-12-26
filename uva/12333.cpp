#include <iostream>
#include <vector> 
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Number{
	Number* next_digit[10];
	int fab_index[10];
};

void get_next_fab(int* a, int* b, int& n){	//assume a>b
	int carry = 0,i;
	for(i=0;i<n;i++){
		b[i+1] += (b[i] + a[i] + carry) / 10;
		b[i] = (b[i] + a[i] + carry) % 10;
	}
	if(b[i] !=0)
		n++;
	return ;
}

void find(Number* num, char* tmp, int& ans){
	Number* walker = num;
	int i,digit;
	for(i=0;i<strlen(tmp);i++){
		digit = tmp[i] - '0';
		ans = walker->fab_index[digit];
		if(ans == -1)
			return;
		walker = walker->next_digit[digit];
	}
	return ;
}

void add_fab(Number* num, int* a, int n, int fab){
	while(a[--n] == 0) ;
	Number* walker = num;
	int digit,i,digit_len=0;
	while(n>=0&&digit_len<40){
		digit = a[n];
		if(walker->fab_index[digit] == -1)
			walker-> fab_index[digit] = fab;
		if(--n < 0)
			break;
		if(!walker->next_digit[digit]){
			walker->next_digit[digit] = new Number();
			for(i=0;i<10;i++){
				walker->next_digit[digit]->next_digit[i] = NULL;
				walker->next_digit[digit]->fab_index[i] = -1;
			}
		}
		walker = walker->next_digit[digit];
		digit_len ++ ;
	}
	return ;
}
int main(){
	Number* num;
	int T,i,j,ans,n;
	int *a, *b, *tmp2;
	char tmp[41];
	scanf("%d",&T);
	num = new Number();
	a = (int*) malloc(sizeof(int) * 100000);
	b = (int*) malloc(sizeof(int) * 100000);
	a[0] = 1, b[0] = 1;
	n=1;
	for(j=0; j<10; j++){
		num->next_digit[j] = NULL;
		num->fab_index[j] = -1;
	}
	add_fab(num,a,n,0);
	add_fab(num,a,n,1);
	for(i=0;i<49999;i++){	
		get_next_fab(b,a,n);
		add_fab(num,a,n,2*i+2);
		get_next_fab(a,b,n);
		add_fab(num,b,n,2*i+3);
	}
	free(a);
	free(b);

	for(i=1;i<=T;i++){		
		scanf("%s",tmp);
		find(num,tmp,ans);
		printf("Case #%d: %d\n", i,ans);
	}
	return 0;
}