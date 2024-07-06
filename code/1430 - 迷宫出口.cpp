#include<bits/stdc++.h>
using namespace std;
int n,mapp[105][105],ha,la,hb,lb;
bool vis[105][105];
string s="NO";
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool f;
void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<=0||xx>n||yy<=0||yy>n) continue;
		if(mapp[xx][yy]==0&&!vis[xx][yy]){
			if(xx==hb&&yy==lb){
				f=true;
		    	break;
			} 
		    vis[xx][yy]=1;
			dfs(xx,yy);
	    }
    }
	return;
	}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>mapp[i][j];
		}
	}
    cin>>ha>>la>>hb>>lb;
	if(mapp[ha][la]==1||mapp[hb][lb]==1){
		cout<<"NO"<<endl;
		return 0;
	}
	vis[ha][la]=1;
	dfs(ha,la);
	if(f) cout<<"YES"<<endl;
	 else 	cout<<"NO"<<endl;
	return 0;
} 
//https://oj.czos.cn/p/1430
