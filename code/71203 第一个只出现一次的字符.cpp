#include<bits/stdc++.h>
using namespace std;
string s;
int abc[27]; 
bool flag;
int main(){
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		abc[s[i]-'a']++;
	}
	for(int i=0;i<len;i++){
		if(abc[s[i]-'a']==1){
			cout<<s[i]<<endl;
			flag=true;
			break;
		}
	}
	if(!flag) cout<<"no"<<endl;
	return 0;
} 
