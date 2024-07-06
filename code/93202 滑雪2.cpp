#include<bits/stdc++.h>
using namespace std;
int r,c,a[105][105],f[105][105],ans;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int dfs(int x,int y){
	if(f[x][y]!=0) return f[x][y];
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(a[x][y]>a[xx][yy]&&xx<=r&&xx>0&&yy<=c&&yy>0) f[x][y]=max(f[x][y],dfs(xx,yy));
	}
	return ++f[x][y];
}
int main(){
	cin>>r>>c;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>a[i][j];
		}
	} 
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			ans=max(ans,dfs(i,j));
		}
	}
	cout<<ans<<endl;
	return 0;
} 
