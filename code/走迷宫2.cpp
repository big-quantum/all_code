#include<bits/stdc++.h>
using namespace std;
struct a{
	int x,y,s;
}q[2500];
int mas[50][50],front,last,r,c;
bool visit[50][50];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char ch;
int main(){
	cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
        	cin>>ch;
			if (ch=='.') mas[i][j]=1;
            else mas[i][j]=0;
		}
    }
    front=0;
	last=0;
	q[last].x=1;
	q[last].y=1;
	q[last].s=1;
	visit[1][1]=true;
	last++;
	while (front<last){
		int t=front;
		for(int i=0;i<4;i++){
			int tx=q[t].x+dx[i];
			int ty=q[t].y+dy[i];
			if(mas[tx][ty]==1&&!visit[tx][ty]){
				q[last].x=tx;
				q[last].y=ty;
				q[last].s=q[t].s+1;
				visit[tx][ty]=true;
				if(tx==r&&ty==c){
					cout<<q[last].s<<endl;
					return 0;
				}
				last++;
			} 
		}
		front++; 
	}
	return 0;
}
