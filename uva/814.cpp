#include <iostream> 
#include <map>
#include <set>
#include <string>
#include <vector> 
using namespace std;

void parse(string s1, string& name, string& place){
	int a = s1.find("@");
	name = s1.substr(0,a);
	place = s1.substr(a+1);
	return ;
}

int main(){
	set <string> address;
	string name,place,s,s2;
	int n;
	while(cin >> s && s != "*"){
		cin >> place >> n;
		while(n--){
			cin >> s;
			address.insert(s+"@"+place);
		}
	}

	map <string, vector<string> > dest;	//dest[place] = names vector;
	int i,j;

	bool sent;
	string s_name, s_place, data,tmp;
	vector <string> visit_order;
	set <string> dup;
	while(cin >> s && s !="*"){	//sender part
		parse(s,s_name,s_place);
		while(cin >> s2 && s2 != "*"){	//receiver part
			parse(s2,name,place);
			if(!dest[place].size())
				visit_order.push_back(place);
			if(dup.count(s2))
				continue;
			dup.insert(s2);
			if(!address.count(s2))
				dest[place].push_back("_"+name);
			else
				dest[place].push_back(name);
		}
		data = "";
		while(getline(cin,tmp) && tmp!="*")
			if(tmp.size())
				data += "     "+tmp+"\n";
		for(i=0;i<visit_order.size();++i){//Connection between Cairo and MexicoCity
			cout << "Connection between "<< s_place << " and " << visit_order[i] << endl;
			cout << "     HELO "<<s_place << endl<<"     250"<<endl;
			cout << "     MAIL FROM:<" << s_name <<"@"<<s_place << ">\n     250\n";
			place = visit_order[i];
			sent = false;
			for(j=0;j<dest[place].size();j++){
				cout << "     RCPT TO:<";
				if(dest[place][j][0] == '_'){
					cout << dest[place][j].substr(1) <<"@"<<place<<">\n     550\n";
				}
				else{
					sent = true;
					cout << dest[place][j] <<"@"<<place<<">\n     250\n";
				}
			}
			if(sent)
				cout<< "     "<< "DATA\n     354\n" << data << "     .\n     250\n";
			cout << "     QUIT\n     221\n";
		}
		dest.clear();
		visit_order.clear();
		dup.clear();
	}
	return 0;
}