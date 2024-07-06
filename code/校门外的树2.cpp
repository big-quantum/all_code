#include<bits/stdc++.h>
using namespace std;
int tree[10005];
int L,M,ans;
int main() {
	cin>>L>>M;
	for(int i=0;i<=L;i++)
	tree[i]=1;
	for(int i =1;i<=M;i++){
		int x,y;
		cin>>x>>y;
		for(int j=x;j<=y;j++)
		tree[j]=0;
	}
	for(int i=0;i<=L;i++)
	ans=ans+tree[i];
	cout<<ans<<endl;
	return 0;
}
