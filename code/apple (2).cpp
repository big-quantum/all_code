#include<bits/stdc++.h>
using namespace std;
int n,s,l,w[1005],ans;
int main() {
	cin>>n>>l;
	s=l;
	for(int i=1; i<=n; i++)
		cin>>w[i];
	for(int i=1; i<=l; i++) {
		for(int j=1; j<=n; j++)
			if(w[j]==l) {
				ans=w[j];
				break;
			}
		if(ans>0) break;
		l++;
		s--;
		for(int a=1; a<=n; a++){
			if(w[a]==s) {
				ans=w[a];
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
