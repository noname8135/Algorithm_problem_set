#include <iostream>
#include <string>

using namespace std;
//power string
//knuth 

int search(string a, string guess_str, int* fail){
	int i,j;
	//cout << a << "__" << guess_str << endl;
	for(i=1,j=-1;i<guess_str.size() || j>=0 ;i++){
		while(j>=0 && guess_str[j+1]!=a[i])
			j = fail[j];
		if(a[i] == guess_str[j+1])
			j++;
		//cout << j << endl;
		if(j == guess_str.size()-1){
			//cout << "GOT"<< j << endl;
			return i-guess_str.size()+1;
		}
	}	
	return 0;
}

//sample ababcdabeeababcdabababababab
void build_failure(string& p,int failure [])
{		
    for (int i=1, j=failure[0]=-1; i<p.size(); i++)
    {
        //cout << "i = "<<i << ", j = " << j;
        while (j >= 0 && p[j+1] != p[i]){
            j = failure[j];
            //cout<<" finding in previous .."<<j<<endl;
 		}
        // p[i] 終於有用處了，終於可以加長！
        if (p[j+1] == p[i]) 
        	j++;
 			
        // 得到了 failure[i] 的值！
        failure[i] = j;
    }
   	//for(int i=0; i<p.size(); i++)
    //	cout<<"failure "<<i<<" = "<<failure[i]<<endl;
    return ;
}

int main(){
	int failure[1000000];
	string a,b;
	
	int pos;
	bool found;

	while (cin >>a){
		if(a == ".")
			break;
		found = false;
		build_failure(a,failure);	//build failure function
		pos = search(a+a,a,failure);
		if(pos)
			cout<<a.size()/pos<<endl;
		else
			cout<<"1"<<endl;
	}
		
	return 0;
}