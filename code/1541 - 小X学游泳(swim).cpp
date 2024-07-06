#include<bits/stdc++.h>
using namespace std;
int n,m,mapp[35][35],dp[35][35];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};//dx少打了个逗号 
void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>0&&xx<=n&&yy>0&&yy<=m&&dp[x][y]+mapp[xx][yy]<dp[xx][yy]){
			dp[xx][yy]=dp[x][y]+mapp[xx][yy];
			dfs(xx,yy);
		} 
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mapp[i][j];
			dp[i][j]=INT_MAX;
		}
	}
	dp[1][1]=mapp[1][1];
	dfs(1,1);
	cout<<dp[n][m]<<endl;
	return 0;
}
//https://oj.czos.cn/p/1541
