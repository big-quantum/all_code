#include<bits/stdc++.h>
using namespace std;
int n,m,mapp[105][105],ans;
int dx[8]={0,1,1,1,0,-1,-1,-1},dy[8]={-1,-1,0,1,1,1,0,-1};
void bfs(int x,int y){
	for(int i=0;i<8;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>0&&xx<=n&&yy>0&&yy<=m&&mapp[xx][yy]!=0){
			mapp[xx][yy]=0;
			bfs(xx,yy);
		}
	}
	return;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char num;
			cin>>num;
			if(num=='W') mapp[i][j]=1;
			else mapp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mapp[i][j]!=0){
				mapp[i][j]=0;
				bfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
//https://oj.czos.cn/p/1435
