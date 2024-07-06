#include<bits/stdc++.h>
using namespace std;
struct node{
	int t,x;
}; 
queue<node> q;
int n,t,k,c,country[100005],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>k;
		for(int i=1;i<=k;i++){
			cin>>c;
			node h;
			h.t=t;
			h.x=c;
			if(country[c]==0) ans++;
			country[c]++;
			q.push(h);
		}
		while(!q.empty()){
			if(q.front().t+86400<=t){
				country[q.front().x]--;
				if(country[q.front().x]==0) ans--;
				q.pop();
			} else {
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
