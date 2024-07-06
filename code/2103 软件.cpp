#include<bits/stdc++.h>
using namespace std;
int n;
string s; 
int main(){
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		int w;
		cin>>w;
		if(w==1){
			string s1;
			cin>>s1;
			s.append(s1);
			cout<<s<<endl;
		}
		if(w==2){
			int a,b;
			cin>>a>>b;
			s=s.substr(a,b);
			cout<<s<<endl;
		}
		if(w==3){
			int a;
			string s1;
			cin>>a>>s1;
			s.insert(a,s1);
			cout<<s<<endl;
		}
		if(w==4){
			string s1;
			cin>>s1;
			if(s.find(s1)==string::npos) cout<<-1<<endl;
			else cout<<s.find(s1)<<endl;
		}
	}
	return 0;
}
