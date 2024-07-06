#include<bits/stdc++.h>
using namespace std;
int n,m,mapp[105][105];
int dx[2]={1,0},dy[2]={0,1};
void bfs(int x,int y){
	for(int i=0;i<2;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>1&&xx<n&&yy>1&&yy<n&&mapp[xx][yy]==0){
			mapp[xx][yy]=2;
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
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mapp[i][j]==1){
				bfs(i,j);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<mapp[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
//https://oj.czos.cn/p/1802
