#include <iostream>

using namespace std;

void push(int* S, int a, int& front, int& rear,int n){
	if(--front == -1)
		front = n-1;
	S[front] = a;
	return ;
}

int pop(int* S, int& front, int& rear, int n){
	int ret = S[rear];
	if(--rear == -1)
		rear = n-1;
	return ret;
}

int main(){
	int n,i,drop,rear,front;
	int S[51];
	while(cin >> n && n){
		for(i=0;i<n;i++)
			S[i] = n-i;
		front=0, rear=n-1;
		cout << "Discarded cards:";
		if(n > 1)
			cout << " " << pop(S,front,rear,n);
		while(1){
			if(rear == front)
				break;
			drop = pop(S,front,rear,n);
			push(S,drop,front,rear,n);
			cout << ", " << pop(S,front,rear,n);
		}
		cout << "\nRemaining card: " << S[front]<<endl;
	}
	return 0;
}