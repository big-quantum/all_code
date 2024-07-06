#include<bits/stdc++.h>
using namespace std;
int n,s[40][40],x,y;
bool flag;
void clean(int i,int j){
	x=i;
	y=j;
}
int main(){
	cin>>n;
	s[1][n/2+1]=1;	
	clean(1,n/2+1);
	for(int k=2;k<=n*n;k++){
		if(x==1&&y!=n){
			s[n][y+1]=k;
			clean(n,y+1);
			continue; 
		}
		if(x!=1&&y==n){
			s[x-1][1]=k;
			clean(x-1,1);
			continue; 
		}
		if(x==1&&y==n){
			s[x+1][y]=k;
			clean(x+1,y);
			continue; 
		}
		if(x!=1&&y!=n&&s[x-1][y+1]==0){
			s[x-1][y+1]=k;
			clean(x-1,y+1);
			continue; 
		} else {
			s[x+1][y]=k;
			clean(x+1,y);
			continue; 
		}
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<s[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0; 
} 
