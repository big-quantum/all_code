#include<bits/stdc++.h>
using namespace std;
int n,tower[105][105],ans; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>tower[i][j];
			tower[i+1][j]+=tower[i][j];
			tower[i+1][j+1]+=tower[i][j];
		} 
	}
	for(int i=1;i<=n;i++){
		if(tower[n][i]>ans){
			ans=tower[n][i];
		}
	}
	cout<<ans<<endl;
	return 0;
}

