#include <iostream>
//Iterative depening algorithm
//limit the max depth
using namespace std;
int min_xv;
bool found;

int heu(int* a,int n){	//at most -3 every xv operation
	int i,counter=0;
	for(i=0;i<n-1;i++){
		if(a[i] > a[i+1])
			counter++;
	}
	return counter;
}

void dfs(int* a, int n, int xv_count, int max_dep){ //insert n consecutive elements from start into the right place
	int now_heu = heu(a,n);
	if(found)
		return ;
	else if(now_heu == 0){ 	//match goal state
		found = true;
		return ;
	} 
	else if( xv_count + now_heu > max_dep)
		return ;
	int x[9],left[9],next[9],i,xcount,start=0,v;	//x_count = pick up this time, start = starting index
	for(xcount=1;xcount<n;xcount++){
		for(start=0;start+xcount<=n;start++){
			for(i=0;i<start;i++)
				left[i] = a[i];
			for(;i<start+xcount;i++)
				x[i-start] = a[i];
			for(;i<n;i++)
				left[i-xcount] = a[i];
			for(v=0;v<start;v++){	//paste at v index
				for(i=0;i<v;i++)
					next[i] = left[i];
				for(;i<v+xcount;i++)
					next[i] = x[i-v];
				for(;i<n;i++)
					next[i] = left[i-xcount];
				if(heu(next,n) <= now_heu)
					dfs(next, n, xv_count+1,max_dep);
			}
		}
	}
	return ;
}

int main(){
	int case_count=0,n,ary[10],i,cv_count,j;

	while(++case_count){
		cin>>n;
		if(!n)
			break;
		cv_count = 0;
		for(i=0;i<n;i++)
			cin>>ary[i];
		found = false;
		for(i=0;!found;i++)
			dfs(ary,n,0,i);
		cout << "Case "<< case_count << ": " << i-1 << endl;
	}
	return 0;
}