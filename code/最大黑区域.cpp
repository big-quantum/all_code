#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
bool mapp[101][101];
int d[10005][2],minn;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void bfs(int x,int y){
	int nx,ny;
	int f=0;
	int l=1;
	d[f][0]=x;
	d[l][1]=y;
	while(f<l){
		nx=d[f][0];
		ny=d[l][1];
		for(int i=0;i<4;i++){
			int tx=nx+dx[i];
			int ty=ny+dy[i];
			if(tx>0&&tx<n&&ty>0&&ty<m&&mapp[nx][ny]==true){
				 //少点东西 
				bfs(tx,ty);
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mapp[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mapp[i][j]){
				bfs(i,j);
				ans=max(ans,minn); 
				//少点东西
			} 
		}
	}
	cout<<ans<<endl;
	return 0;
}

