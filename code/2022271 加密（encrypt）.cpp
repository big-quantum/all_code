#include<bits/stdc++.h>
using namespace std;
long long len,k=1;
long long ans;
string s;
int main(){
	cin>>s;
	len=s.size();
	for(int i=len-1;i>=0;i--){
		ans+=(s[i]-'0')*k;
		k=k*2;
	}
	//if(s[0]=='0') ans=ans*-1;
	cout<<ans<<endl;
} 
