#include<bits/stdc++.h>
using namespace std;
char mapp[25][25];
int n,m,ans,maxans;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct node{
	int x,y,step;
}que[10005];
bool mabb[25][25];
int bfs(int i,int j){
	int front=0,rear=1;
	que[front].x=i;
	que[front].y=j;
	que[front].step=0;
	int maxstep=0;
	while(front<rear){
		for(int i=0;i<4;i++){
			int xx=que[front].x+dx[i];
			int yy=que[front].y+dy[i];
			if(xx>0&&yy>0&&xx<=n&&yy<=m&&mapp[xx][yy]=='.'&&!mabb[xx][yy]){
				que[rear].x=xx;
				que[rear].y=yy;
				que[rear].step=que[front].step+1;
				mabb[xx][yy]=true;
				maxstep=max(que[rear].step,maxstep);
				rear++;
			}
		}
		front++;
	}
	return maxstep;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mapp[i][j];
			if(mapp[i][j]=='.') mabb[i][j]=false;
			else mabb[i][j]=true;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mapp[i][j]=='.'){
				for(int x=1;x<=n;x++){
					for(int y=1;y<=m;y++){
						if(mapp[x][y]=='.') mabb[x][y]=false;
						else mabb[x][y]=true;
					}
				}
				ans=bfs(i,j);
				maxans=max(maxans,ans);
			}
		}
	}
	cout<<maxans<<endl;
	return 0; 
}
