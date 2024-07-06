#include<bits/stdc++.h>
using namespace std;
int n,m,mapp[105][105];
//bool vis[105][105];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void bfs(int x,int y){
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>=0&&xx<=n+1&&yy>=0&&yy<=n+1&&mapp[xx][yy]==0/*&&!vis[xx][yy]*/){
			mapp[xx][yy]=2;
			//vis[xx][yy]=true;
			bfs(xx,yy);
		}
	}
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>mapp[i][j];
		}
	}
	bfs(0,0);
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mapp[i][j]==1){
				bfs(i,j);
			}
		}
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mapp[i][j]==1) cout<<1<<" ";
			else if(mapp[i][j]==2) cout<<0<<" ";
				 else cout<<2<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
//https://oj.czos.cn/p/1802
