1¡¤#include<bits/stdc++.h>
using namespace std;
int n,m,f,r,ans=-1,Map[505][505],x,y;
struct node{
	int p,q,step;
}que[250005];
bool vis[505][505];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>Map[i][j];
	cin>>x>>y;
	f=r=1;
	que[f].p = x;
	que[f].q = y;
	vis[x][y] = true;
	while(f<=r){
		if(que[f].p == n && que[f].q == m){
			ans = que[f].step;
			break;
		}
		for(int k=0;k<4;k++){
			int nx = que[f].p+dx[k];
			int ny = que[f].q+dy[k];
			if(nx>0&&nx<=n&&ny>0&&ny<=m&&!vis[nx][ny]&&Map[nx][ny] == false){
				r++;
				que[r].p = nx;
				que[r].q = ny;
				que[r].step = que[f].step+1;
				vis[nx][ny] = true;
			}	
		}
		f++;
	}
	cout<<ans<<endl;
} 
