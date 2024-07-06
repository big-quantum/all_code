#include<bits/stdc++.h>
using namespace std;
int n,work[15][15],ans=INT_MAX;
bool visit[15];
void dfs(int worker,int time){
	if(time>=ans) return;
	if(worker>n){
		ans=min(ans,time);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			visit[i]=true;
			dfs(worker+1,time+work[worker][i]);
			visit[i]=false;
		}else continue;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>work[i][j];
		}
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
} 
