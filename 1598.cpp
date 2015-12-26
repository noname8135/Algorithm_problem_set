#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
struct BOOK{
	bool is_buy; //buy or sell
	int quan,price;	
};

int main(){
	int n,i,cmd_counter,cancel;
	string cmd;
	vector <BOOK> book;
	BOOK input;
	cin >> n;
	cmd_counter=0;
	while(n--){
		cin >> cmd;
		if(cmd == 'BUY'){
			input.is_buy = true;
			cin >> input.quan >> input.price;
			book.push_back(input);
		}
		else if(cmd == "CANCEL"){
			cin >> cancel;
			book.erase(book.begin()+cancel-1);
		}
		else{	//SELL
			input.is_buy = false;
			cin >> input.quan >> input.price;
			book.push_back(input);
		}	
	}
		
	return 0;
}