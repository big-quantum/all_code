#include<bits/stdc++.h>
using namespace std;
int n,m,t,sx,sy,fx,fy,mapp[10][10],ans;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool vis[10][10];
void dfs(int x,int y){
	if(x==fx&&y==fy){
		ans++;
		return;
	}
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>0&&xx<=n&&yy>0&&yy<=m&&!vis[xx][yy]&&!mapp[xx][yy]){
			vis[xx][yy]=true;
			dfs(xx,yy);
			vis[xx][yy]=false;
		}
	}
} 
int main(){
	cin>>n>>m>>t;
	cin>>sx>>sy>>fx>>fy;
	for(int i=1;i<=t;i++){
		int tmpx,tmpy;
		cin>>tmpx>>tmpy;
		mapp[tmpx][tmpy]=1;
	}
	vis[sx][sy]=true;
	dfs(sx,sy);
	cout<<ans<<endl;
	return 0;
}
//https://www.luogu.com.cn/problem/P1605
