#include<bits/stdc++.h>
using namespace std;
int r,c,cnt,ans,snow[105][105],f[105][105];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
struct node{
	int x,y,high; 
}a[10005];
bool cmp(node a,node b){
	if(a.high<b.high) return true;
	else return false;
}
int main(){
	cin>>r>>c;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>snow[i][j];
			a[++cnt].x=i;
			a[cnt].y=j;
			a[cnt].high=snow[i][j];
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int x=a[i].x,y=a[i].y;
		f[x][y]=1;
		for(int j=0;j<4;j++){
			int xx=x+dx[j],yy=y+dy[j];
			if(a[i].high>snow[xx][yy]) f[x][y]=max(f[xx][yy]+1,f[x][y]); 
		}
		ans=max(ans,f[x][y]);
	}
	cout<<ans<<endl;
	return 0;
}
