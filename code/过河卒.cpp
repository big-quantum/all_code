#include<bits/stdc++.h>
using namespace std;
bool b[505][505];
long long a[505][505];
int dx[8]={2,1,-1,-2,-2,-1,1,2},dy[8]={1,2,2,1,-1,-2,-2,-1},n,m,x,y,k,l;
int main(){
	cin>>n>>m>>x>>y;
	b[x][y]=true;
	for(int i=0;i<=7;i++){
		if(x+dx[i]>=0&&x+dx[i]<=n&&y+dy[i]>=0&&y+dy[i]<=m){
			b[x+dx[i]][y+dy[i]]=1;
		}
	}
	while(!b[k][0]&&k<=n){
		a[k++][0]=1;
	}
	while(!b[0][l]&&l<=m){
		a[0][l++]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]){
				a[i][j]=0;
			} else {
				a[i][j]=a[i-1][j]+a[i][j-1];
			}
		}
	}
	cout<<a[n][m]<<endl;
	return 0;
} 
