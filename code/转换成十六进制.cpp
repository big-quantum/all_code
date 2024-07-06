#include<bits/stdc++.h>
using namespace std;
string s,ans;
int main(){
	getline(cin,s);
	for(int i=s.size();i>0;i-=4){
		int t=0;
		for(int j=max(0,i-4);j<i;j++){
			t=t*2+s[j]-'0';
		}
		if(t<10) ans=char(t+'0')+ans;
		else ans=char(t-10+'A')+ans;
	}
	cout<<ans<<endl;
	return 0;
} 
