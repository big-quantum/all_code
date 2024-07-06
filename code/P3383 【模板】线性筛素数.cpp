#include<bits/stdc++.h>
using namespace std;
int n,q,prime[10000505],cnt,m;
bool isprime[100000505];
void gets(){
	isprime[1]=true;
	for(int i=2;i<=n;i++){
		if(!isprime[i]) prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			isprime[i*prime[j]]=true;
			if(i%prime[j]==0) break;
		}
 	}
}
int main(){
	cin>>n>>q;
	gets();
	for(int i=1;i<=q;i++){
		cin>>m;
		cout<<prime[m]<<endl;
	}
	return 0; 
}
