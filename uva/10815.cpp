#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
	string str;
	set <string> dict;
	int i,word_len;
	string tmp;
	while(cin >> str){
		tmp = "";
		for(i=0;i<str.size();i++){
			if(str[i] >='a' && str[i]<='z')
				tmp+= str[i];
			else if(str[i]>='A' && str[i]<='Z')
				tmp+= (str[i]-'A'+'a');
			else{
				dict.insert(tmp);
				tmp = "";
			}

		}
		dict.insert(tmp);
		tmp = "";
	}
	dict.erase("");
	for(set <string>::iterator i=dict.begin(); i!= dict.end() ;i++)
		cout << *i << endl;
	return 0;
}
