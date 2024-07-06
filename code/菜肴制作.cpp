#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int in[100005],ans[100005];
vector<int> graf[100005];
int main() {
	cin>>t;
	for(int i=1; i<=t; i++) {
		cin>>n>>m;
		int tot=0;
		for(int j=1; j<=m; j++) {
			int x,y;
			cin>>x>>y;
			graf[y].push_back(x);
			in[x]++;
		}
		
		priority_queue<int> q;
		for(int j=1; j<=n; j++) {
			if(!in[j]) {
				q.push(j);
			}
		}
		
		while(!q.empty()) {
			int from=q.top();
			q.pop();
			ans[++tot]=from;
			
			for(vector<int>::iterator it=graf[from].begin();it!=graf[from].end();it++) {
				in[*it]--;
				if(!in[*it]) q.push(*it);
			}
		}
		if(tot==n){
			for(int j=n;j>=1;j--){
				cout<<ans[j]<<" ";
			}
			cout<<endl;
		} else {
			cout<<"Impossible!"<<endl;
		}
		memset(in,0,sizeof(in));
		memset(ans,0,sizeof(ans));
		for(int j=1;j<=n;j++){
			graf[j].clear();
		}
	}
	return 0;
}
