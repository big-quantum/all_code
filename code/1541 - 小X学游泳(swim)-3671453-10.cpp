#include<bits/stdc++.h>//³¬Ê± 
using namespace std;
int n,m,ans=INT_MAX,mapp[35][35];
bool flag[35][35];
int dx[4]={0,1,0-1},dy[4]={1,0,-1,0};
void dfs(int x,int y,int step){
	if(x==n&&y==m) {
		ans=min(ans,step);
		return; 
	}
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>0&&xx<=n&&yy>0&&yy<=m&&!flag[xx][yy]){
			flag[xx][yy]=true;
			dfs(xx,yy,step+mapp[xx][yy]);
			flag[xx][yy]=false;
		} 
	}
	return;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mapp[i][j];
		}
	}
	flag[1][1]=true;
	dfs(1,1,mapp[1][1]);
	cout<<ans<<endl;
	return 0;
}
//https://oj.czos.cn/p/1541
