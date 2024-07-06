#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
bool mapp[105][105];
bool vis[105][105];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int area=0;
void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>0&&xx<=n&&yy>0&&yy<=m&&mapp[xx][yy]&&!vis[xx][yy]){
			vis[xx][yy]=1;
			area++;
			dfs(xx,yy);
			}
	}
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		mapp[x][y]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mapp[i][j]){
				vis[i][j]=1;
				area=1;
				dfs(i,j);
				ans=max(area,ans);
			}
		} 
	}
	cout<<ans<<endl;
	return 0;
}//没有必要回溯，浪费时间 
//https://jsoi.jzhx.net/question/2022072003
