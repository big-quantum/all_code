#include<bits/stdc++.h>
using namespace std;
int r,c,snow[105][105],maxnum,maxx,maxy,ans=1;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main(){
	cin>>r>>c;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>snow[i][j];
			if(snow[i][j]>maxnum){
				maxnum=snow[i][j];
				maxx=i;
				maxy=j;
			}
		}
	}
	for(int i=maxnum;i>=0;i--){
		for(int j=0;j<4;j++){
			if(snow[maxx+dx[j]][maxy+dy[j]]==i&&snow[maxx+dx[j]][maxy+dy[j]]!=0){
				ans++;
				maxx+=dx[j];
				maxy+=dy[j];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
