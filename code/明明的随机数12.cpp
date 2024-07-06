#include<bits/stdc++.h>
using namespace std;
int n,s[1005],a,ans; 
int main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		s[a]++;
	}
	for(int i=1;i<=1003;i++){
		if(s[i]!=0) ans++;
	}
	cout<<ans<<endl;
	for(int i=1;i<=1003;i++){
		if(s[i]!=0) cout<<i<<" ";
	}
	cout<<endl;
}
