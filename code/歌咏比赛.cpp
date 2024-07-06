#include<bits/stdc++.h>
using namespace std;
int s[10005][15],m,n,maxx=-1,minn=101;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m+1;j++){
			cin>>s[i][j];
			if(j!=1) s[i][m+2]+=s[i][j];
			if(j!=1&&s[i][j]>maxx) maxx=s[i][j];
			if(j!=1&&s[i][j]<minn) minn=s[i][j];
		}
		s[i][m+2]-=maxx;
		s[i][m+2]-=minn;
		maxx=-1;
		minn=101;
	}
	for(int i=1;i<=n;i++){
		s[i][m+3]=1;
		for(int j=1;j<=n;j++){
			if(s[i][m+2]<s[j][m+2]) s[i][m+3]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i][m+3]<=10) cout<<s[i][1]<<" "<<s[i][m+2]<<" "<<s[i][m+3]<<endl;
	}
}
