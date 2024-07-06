#include<bits/stdc++.h>
using namespace std;
int n,m,mapp[15][15];
bool flag[15][15];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void bfs(int x,int y,int num){
	mapp[x][y]=num;
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>0&&xx<=n&&yy>0&&yy<=m&&!flag[xx][yy]){
			flag[xx][yy]=true;
			bfs(xx,yy,num+1);
		}
	}
	return;
}
int main(){
	cin>>n>>m;
	flag[1][1]=true;
	bfs(1,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%3d",mapp[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
//https://oj.czos.cn/p/1586
