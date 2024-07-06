#include<bits/stdc++.h>
using namespace std;
bool p[10000005];
int ans,n;
int main(){
	cin>>n;
	for(int i=2;i<=n+5;i++){
		if(!p[i]){
			for(int j=2;j<=n/i;j++){
				p[i*j]=true; 
			}
		}
	}
	for(int i=2;i<=n/2;i++){
		if(!p[i]&&!p[n-i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
} 
