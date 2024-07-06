#include<bits/stdc++.h>
using namespace std;
string n;
int ans;
int main(){
	cin>>n;
	int len=n.size();
	char tmp=n[0];
	for(int i=0;i<=len;i++){
		if(n[i]==tmp){
			ans++;
		} else {
			if(ans!=1) cout<<ans<<tmp;
			else cout<<tmp;
			tmp=n[i];
			ans=1;
		}
	}
	return 0;
}
