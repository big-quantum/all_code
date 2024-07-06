#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,x,y;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool a[105][105];
int dfs(int x1,int y1){
	a[x1][y1]=0;
	int tot=1;
	for(int i=0;i<4;i++){
		int xx=x1+dx[i];
		int yy=y1+dy[i];
		if(xx>0&&yy>0&&xx<=n&&yy<=m&&a[xx][yy]==true){
			tot+=dfs(xx,yy);
		}
	}
	return tot;
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		cin>>x>>y;
		a[x][y]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]){
				ans=max(ans,dfs(i,j));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
