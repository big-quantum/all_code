#include<bits/stdc++.h>
using namespace std;
int n,x[105],w[105][2];
bool visit[105];
int dfs(int cnt,int cow){
	while(!visit[cow]){
		visit[cow]=true;
		if(w[cow][1]>w[cow][0]&&visit[cow-1]) cow++;
		else dfs(cnt+1,cow+1);
		if(cow==n) return cnt;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x,x+1+n);
	w[1][1]=x[2]-x[1];
	w[n][0]=x[n]-x[n-1];
	for(int i=2;i<n;i++){
		w[i][0]=x[i]-x[i-1];
		w[i][1]=x[i+1]-x[i];
	}
	cout<<dfs(1,1)<<endl;
	return 0;
} 
