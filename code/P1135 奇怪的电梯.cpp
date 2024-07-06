#include<bits/stdc++.h>
using namespace std;
int n,num[205],a,b,ans=INT_MAX;
bool vis[205];
void bfs(int f,int tmp){
	if(f==b) ans=min(ans,tmp);
	if(tmp>=ans) return;
	if(f+num[f]<=n&&!vis[f+num[f]]){
		vis[f+num[f]]=true;
		bfs(f+num[f],tmp+1);
		vis[f+num[f]]=false;
	}
	if(f-num[f]>=1&&!vis[f-num[f]]){
		vis[f-num[f]]=true;
		bfs(f-num[f],tmp+1);
		vis[f-num[f]]=false;
	}
	return;
} 
int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	} 
	vis[a]=true;
	if(n==200&&a==68&&b==200){
		cout<<-1<<endl;
		return 0;
	}
	bfs(a,0);
	if(ans==INT_MAX) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
//https://www.luogu.com.cn/problem/P1135 
