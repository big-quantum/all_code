#include<bits/stdc++.h>
using namespace std;
bool vis[205];
int n,mem[205][205],pep[205];
int ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int tmp;
		do {
			cin>>tmp;
			mem[i][tmp]=1;
		} while(tmp);
		pep[i]=i;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mem[i][j]=mem[i][j]||(mem[i][k]&&mem[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mem[i][j]) pep[j]=pep[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(pep[i]==i) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
