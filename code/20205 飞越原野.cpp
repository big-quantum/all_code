#include<bits/stdc++.h>
using namespace std;
int n,m,d,mapp[105][105];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char a;
bool visit[105][105][105];
struct node{
	int x,y,time,dd;
};
queue<node>que;
void bfs(int x,int y,int t){
	que.push(node{x,y,t,d});
	while(!que.empty()){
		cout<<que.front().x<<" "<<que.front().y<<" "<<que.front().time<<" "<<que.front().dd<<endl;
		if(que.front().x==m&&que.front().y==n){
			cout<<que.front().time<<endl;
			return;
		}
		for(int i=0;i<4;i++){
			int xx=que.front().x+dx[i];
			int yy=que.front().y+dy[i];
			if(xx>0&&xx<=m&&yy>0&&yy<=n&&mapp[xx][yy]==0&&!visit[xx][yy][que.front().dd]){
				visit[xx][yy][que.front().dd]=true;
				if(xx==m&&yy==n){
					cout<<que.front().time+1<<endl;
					return;
				}
				que.push(node{xx,yy,que.front().time+1,d});
			}
		}
		for(int j=0;j<4;j++){
			for(int i=2;i<=que.front().dd;i++){
				int xx=que.front().x+i*dx[j];
				int yy=que.front().y+i*dy[j];
				if(xx>0&&xx<=m&&yy>0&&yy<=n&&!mapp[xx][yy]&&!visit[xx][yy][que.front().dd]){
					visit[xx][yy][que.front().dd]=true;
					if(xx==m&&yy==n){
						cout<<que.front().time+1<<endl;
						return;
					}
					que.push(node{xx,yy,que.front().time+1,que.front().dd-i});
				}
			}
		}
		que.pop();
	}
	cout<<"impossible"<<endl;
	return;
}
int main(){
	cin>>m>>n>>d;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a;
			if(a=='L') mapp[i][j]=1;
		}
	}
	visit[1][1][d]=true;
	bfs(1,1,0);
	return 0;
} 
