#include<bits/stdc++.h>
using namespace std;
int n,m,t,sx,sy,fx,fy,mapp[10][10],ans;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
struct node{
	int x,y;
	bool vis[10][10];
};
queue<node> que;
void bfs(){
	node a;
	a.x=sx;
	a.y=sy;
	a.vis[sx][sy]=true;
	que.push(a);
	while(!que.empty()){
		for(int i=0;i<4;i++){
			int xx=que.front().x+dx[i],yy=que.front().y+dy[i];
			if(xx>0&&xx<=n&&yy>0&&yy<=m&&!mapp[xx][yy]&&!que.front().vis[xx][yy]){
				if(xx==fx&&yy==fy){
					ans++;
					continue;
				}
				node tmp;
				tmp.x=xx;
				tmp.y=yy;
				for(int j=1;j<=n;j++){
					for(int k=1;k<=m;k++){
						tmp.vis[j][k]=que.front().vis[j][k];
					}
				}
				tmp.vis[xx][yy]=true;
				que.push(tmp);
			}
		}
		que.pop();
	}
} 
int main(){
	cin>>n>>m>>t;
	cin>>sx>>sy>>fx>>fy;
	for(int i=1;i<=t;i++){
		int tmpx,tmpy;
		cin>>tmpx>>tmpy;
		mapp[tmpx][tmpy]=1;
	}
	bfs();
	cout<<ans<<endl;
	return 0;
}
//https://www.luogu.com.cn/problem/P1605
