#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

int get_inside_num(string a,int walker,int end, map <string, int> ary,bool& error,map <char, int> initialize){
	if(a[walker] >='0' && a[walker] <='9'){
		int length = 0;
		while(a[walker+length] >= '0' && a[walker+length] <= '9')
			length++;
		return stoi(a.substr(walker,length));
	}
	else if( (a[walker] >='a' && a[walker] <= 'z') || (a[walker]>='A' && a[walker]<='Z')){
		int inside_num = get_inside_num(a,walker+2,end,ary,error,initialize);
		string index = a[walker]+to_string(inside_num);
		if(ary.count(index) && inside_num<initialize[a[walker]])
			return ary[a[walker]+to_string(inside_num)];
		else{
			error = true;
			return -1;
		}
	}
	return 123456;
}

int main(){
	string input;
	char ary_name,left;
	map <char, int> initialize;
	map <string, int> ary;
	int inside_num,right,equal_sign,line_count = 0, error_line = 0;
	bool end_flag = false, error=false;
	while(cin >> input){
		line_count ++;
		if(input == "."){
			if(end_flag)
				break;
			cout << error_line << endl;
			line_count = error_line = 0;
			ary.clear();
			initialize.clear();
			end_flag = true;
			error = false;
			continue;
		}
		else if(error)
			continue;
		end_flag = false;
		left = input[0];
		equal_sign = input.find("=");
		inside_num = get_inside_num(input,2,input.size(),ary,error,initialize);
		//cout << "left = " << left << ", inside_num = " << inside_num << ", error?" << error << endl;
		if(error){
			error_line = line_count;
			continue;
		}
		else if(equal_sign == -1){
			initialize[left] = inside_num;
			continue;
		}
		else if(inside_num >= initialize[left]){
			error = true;
			error_line = line_count;
			continue;
		}
		right = get_inside_num(input,equal_sign+1,input.size(),ary,error,initialize);
		//cout << "right = " << right << ", error?" << error << endl;
		if(error){
			error_line = line_count;
			continue;
		}
		ary[left+to_string(inside_num)] = right;	
	}
	return 0;
}