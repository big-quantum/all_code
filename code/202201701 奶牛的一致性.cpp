#include<bits/stdc++.h>
using namespace std;
int cow[15][25],n,k,ans;
void fid(int x,int y){
	bool flag1=true,flag2=true;
	int a;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(cow[i][j]==x){
				a=j;
				break;
			}
		}
		for(int j=1;j<=n;j++){
			if(cow[i][j]==y){
				//cout<<a<<" "<<j<<"   ";
				if(a>j) flag1=false;
				if(a<j) flag2=false;
			}
		}
	}
	//cout<<endl;
	if(flag1||flag2) ans++;
}
int main(){
	cin>>k>>n;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>cow[i][j];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			//cout<<i<<" "<<j<<"    "; 
			fid(i,j);
		}
	}
	cout<<ans<<endl;
	return 0;
}
