#include<bits/stdc++.h>
using namespace std;
int n,m,mapp[105][105],place,maxx,maxy,minx,miny,cows,house,space;
char a;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
//struct node{
//	int x,y;
//}que[10005];
void check(int x,int y){
	maxx=max(maxx,x);
	minx=min(minx,x);
	maxy=max(maxy,y);
	miny=min(miny,y);
}
void clean(){
	maxx=-1;
	maxy=-1;
	minx=INT_MAX;
	miny=INT_MAX;
}
void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>0&&yy>0&&xx<=n&&yy<=m&&mapp[xx][yy]){
			check(xx,yy);
			space++;
			mapp[xx][yy]=0;
			dfs(xx,yy);
		}
	}
} 
/*int bfs(int x,int y){
	int front=0,rear=1;
	que[front].x=x;
	que[front].y=y;
	int space=1;
	while(front<rear){
		for(int i=0;i<4;i++){
			int xx=que[front].x+dx[i];
			int yy=que[front].y+dy[i];
			if(xx>0&&yy>0&&xx<=n&&yy<=m&&mapp[xx][yy]){
				que[rear].x=xx;
				que[rear].y=yy;
				check(xx,yy);
				space++;
				mapp[xx][yy]=0;
				rear++;
			}
		}
		front++;
	}
	return space;
}*/
int main(){
	clean();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a;
			if(a=='#') mapp[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mapp[i][j]){
				mapp[i][j]=0;
				space=1;
				check(i,j);
				//place=bfs(i,j);
				dfs(i,j);
				if(space==(maxx-minx+1)*(maxy-miny+1)) house++;
				//if(place==(maxx-minx+1)*(maxy-miny+1)) house++;
				else cows++;
				clean();
				space=0;
			}
		}
	}
	cout<<house<<endl;
	cout<<cows<<endl;
	return 0; 
}
