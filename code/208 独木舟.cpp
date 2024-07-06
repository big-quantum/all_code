#include<bits/stdc++.h>
using namespace std;
int w,n,a[30005],maxx,maxa,ans;
bool vis[30005],flag;
int main(){
	cin>>w;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		for(int j=n;j>=1;j--){
			if(i==j) continue; 
			if(!vis[j]&&a[i]+a[j]<=w){
				maxa=j;
				flag=true;
				break;
			}
		}
		if(flag){
			vis[i]=true;
			vis[maxa]=true;
			ans++;
		}
		flag=false;
		maxx=0;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
} 
