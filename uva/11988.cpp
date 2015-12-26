#include <iostream>
#include <string> 
#include <algorithm>

using namespace std;

struct NODE{
	NODE* next;
	string text;
};

void output_text(NODE* node){
	while(node){
		cout << node->text;
		node = node->next;
	}
	return ;
}

int main(){
	NODE* start;
	NODE* tail;
	NODE* tmp;	
	int from,walker;
	string input;
	bool to_head;	//append next string to head or tail
	while(getline(cin,input)){
		walker=0;
		while(input[walker] != '[' && input[walker] !=']')
			walker++;
		tail = start = new NODE();
		start->text = input.substr(0,walker);
		start->next = NULL;
		to_head = input[walker] == '[' ? true:false;
		from = ++walker;
		while(walker<input.size()){
			while(input[walker] != '[' && input[walker] !=']' && walker<input.size())
				walker++;
			tmp = new NODE();
			tmp->text = input.substr(from,walker-from);
			if(to_head){
				tmp->next = start;
				start = tmp;
			}
			else{	//append to tail
				tmp->text = input.substr(from,walker-from);
				tmp->next = NULL;
				tail->next = tmp;
				tail = tmp;
			}
			if(walker<input.size()){
				to_head = input[walker] == '[' ? true:false;
				from = ++walker;
			}
		}
		output_text(start);
		cout << endl;
		delete start;
	}

	return 0;
}