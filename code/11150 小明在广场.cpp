#include<bits/stdc++.h>
using namespace std;
int n,m,mapp[55][55],dx[4]={0,0,-1,1},dy[4]={-1,1,0,0},xx,yy;
struct node{
	int x,y;
}que[50000];
char a1;
int bfs(int i,int j){
	int front=0,rear=1;
	que[front].x=i;
	que[front].y=j;
	int space=1;
	while(front<rear){
		for(int i=0;i<4;i++){
			int xx=que[front].x+dx[i];
			int yy=que[front].y+dy[i];
			if(xx>0&&yy>0&&xx<=n&&yy<=m&&mapp[xx][yy]==0){
				que[rear].x=xx;
				que[rear].y=yy;
				space++;
				mapp[xx][yy]=1;
				rear++;
			}
		}
		front++;
	}
	return space;
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a1;
			if(a1=='.') mapp[i][j]=0;
			if(a1=='#') mapp[i][j]=1;
			if(a1=='@'){
				mapp[i][j]=1;
				xx=i;
				yy=j;
			}
		}
	}
	cout<<bfs(xx,yy)<<endl;
	return 0;
}

