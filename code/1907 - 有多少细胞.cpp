#include<bits/stdc++.h>
using namespace std;
int n,m,mapp[105][105],ans;
int dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
void bfs(int x,int y,int area){
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>0&&xx<=m&&yy>0&&yy<=n&&mapp[xx][yy]!=0){
			mapp[xx][yy]=0;
			bfs(xx,yy,area+1);
		}
	}
	return;
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			char num;
			cin>>num;
			mapp[i][j]=num-'0';
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(mapp[i][j]!=0){
				mapp[i][j]=0;
				bfs(i,j,1);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
//https://oj.czos.cn/p/1907
