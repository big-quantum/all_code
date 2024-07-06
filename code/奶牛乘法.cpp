#include<bits/stdc++.h>
using namespace std;
string a,b;
int ans;
int main(){
	cin>>a>>b;
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size();j++)
			ans=ans+(a[i]-'0')*(b[j]-48);
	cout<<ans<<endl;
	return 0;
}
