#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector <vector <int> > word_len;
	vector <int> line; 
	vector <vector <string> > words;
	int walker,start,i,j;
	string tmp;
	int max_words = 0;
	while(getline(cin,tmp)){
		walker = 0;
		words.push_back(vector<string>());
		while(walker < tmp.size()){
			while(tmp[walker]==' ' && tmp[walker] !='\0')
				walker++;
			if(walker == tmp.size())
				break;
			start = walker;
			while(tmp[walker]!=' ' && tmp[walker] !='\0')
				walker++;
			line.push_back(walker-start);
			words[words.size()-1].push_back(tmp.substr(start,walker-start));
		}
		if(words[words.size()-1].size() > max_words)
			max_words = words[words.size()-1].size();
		word_len.push_back(line);
		line.clear();
	}
	vector<int> space;
	for(i=0;i<max_words;i++){
		walker = 0;
		for(j=0;j<word_len.size();j++)
			if(word_len[j].size() > i && word_len[j][i] > walker){
				walker = word_len[j][i];
			}
		space.push_back(walker);
	}
	for(i=0;i<words.size();i++){
		for(j=0;j<words[i].size();j++){
			cout << words[i][j];
			walker = space[j]-words[i][j].size();
			if(j != words[i].size()-1){
				while(walker-- >0 )
					cout << " ";
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}