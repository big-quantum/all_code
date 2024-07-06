#include<bits/stdc++.h>
using namespace std;
int r,c,mapp[105][105],sx,sy,ex,ey,dp[105][105];
bool flag;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void dfs(int x,int y,int step){
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>0&&xx<=r&&yy>0&&yy<=c&&!mapp[xx][yy]&&dp[xx][yy]>step+1){
			dp[xx][yy]=step+1;
			dfs(xx,yy,step+1);
		}
	}
	return;
}
int main(){
	cin>>r>>c;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			char a;
			cin>>a;
			dp[i][j]=INT_MAX;
			if(a=='#'){
				mapp[i][j]=1;
			}
			if(a=='S') {
				sx=i;
				sy=j;
				mapp[i][j]=1;
			}
			if(a=='T'){
				ex=i;
				ey=j;
			}
		}
	}
	dfs(sx,sy,0);
	cout<<dp[ex][ey];
	return 0;
}
//https://oj.czos.cn/p/1433
