#include<bits/stdc++.h>
using namespace std;
int n,m,mapp[105][105],ans;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>0&&xx<=n&&yy>0&&yy<=m&&mapp[xx][yy]==1){
			mapp[xx][yy]=0;
			dfs(xx,yy);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char num;
			cin>>num;
			if(num=='#') mapp[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mapp[i][j]==1){
				mapp[i][j]=0;
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
//https://oj.czos.cn/p/1383
