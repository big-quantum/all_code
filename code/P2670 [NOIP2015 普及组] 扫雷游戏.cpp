#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,place[105][105],u[8][2]={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};
char a;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a;
			if(a=='?') place[i][j]=0;
			else place[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<8;k++)
			if(place[i][j]==-1){
				r=i+u[k][0]; 
				c=j+u[k][1];
				if(r>=1&&r<=n&&c>=1&&c<=m&&place[r][c]!=-1) place[r][c]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(place[i][j]==-1) cout<<"*";
			else cout<<place[i][j];
		}
		cout<<endl;
	}
	return 0;
} 
