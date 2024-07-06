#include<bits/stdc++.h>
using namespace std;
int m,mapp[1005][1005],xx,yy,tt,front=0,rear=1;
bool h[1005][1005];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
struct node{
	int x,y,t;
}que[10005];
/*int bfs(int a,int b){
	int front=0,rear=1;
	que[front].x=a;
	que[front].y=b;
	que[front].t=0;
	h[a][b]=true;
	while(front<rear){
		for(int i=0;i<4;i++){
			int tx=que[front].x+dx[i];
			int ty=que[front].y+dy[i];
			if(mapp[tx][ty]==-1) return que[front].t;
			if(xx>=0&&yy>=0&&mapp[tx][ty]>que[front].t+1&&!h[tx][ty]){
				que[rear].x=tx;
				que[rear].y=ty;
				que[rear].t=que[front].t+1;
				h[tx][ty]=true;
				rear++;
			}
		}
		front++;
	}
	return -1;
}*/
int main(){
	cin>>m;
	memset(mapp,-1,sizeof(mapp)); 
	for(int i=1;i<=m;i++){
		cin>>xx>>yy>>tt;
		if(mapp[xx][yy]==-1){
			mapp[xx][yy]=tt;
		} else {
			mapp[xx][yy]=min(mapp[xx][yy],tt);
		} 
		for(int j=0;j<4;j++){
			if(xx+dx[j]<0||yy+dy[j]<0) continue;
			if(mapp[xx+dx[j]][yy+dy[j]]==-1||mapp[xx+dx[j]][yy+dy[j]]>tt) mapp[xx+dx[j]][yy+dy[j]]=tt;
		}
	}
	que[front].x=0;
	que[front].y=0;
	que[front].t=0;
	h[0][0]=true;
	while(front<rear){
		for(int i=0;i<4;i++){
			int tx=que[front].x+dx[i];
			int ty=que[front].y+dy[i];
			if(tx<0||ty<0) continue;
			if(mapp[tx][ty]>=que[front].t+1&&!h[tx][ty]){
				que[rear].x=tx;
				que[rear].y=ty;
				que[rear].t=que[front].t+1;
				h[tx][ty]=true;
				rear++;
			}
			if(mapp[tx][ty]==-1){
				cout<<que[front].t+1<<endl;
				return 0;
			}
		}
		front++;
	}
	cout<<-1<<endl;
	return 0;
}
