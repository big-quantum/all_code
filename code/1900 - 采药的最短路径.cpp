#include<bits/stdc++.h>
using namespace std;
int mapp[25][25],n,m,sx,sy,fx,fy,ans=INT_MAX;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void dfs(int x,int y,int step){
	if(x==fx&&y==fy){
		ans=min(ans,step);
		return;
	}
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>0&&xx<=n&&yy>0&&yy<=m&&!mapp[xx][yy]){
			mapp[xx][yy]=1;
			dfs(xx,yy,step+1);
			mapp[xx][yy]=0;
		}
	}
	return;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char a;
			cin>>a;
			if(a=='@'){
				sx=i;
				sy=j;
				mapp[i][j]=1;
			}
			if(a=='*'){
				fx=i;
				fy=j;
			}
			if(a=='#') mapp[i][j]=1;
		}
	}
	dfs(sx,sy,0);
	if(ans!=INT_MAX) cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0; 
}
//https://oj.czos.cn/p/1900
