#include<bits/stdc++.h>
using namespace std;
int n,k,num[10005];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num,num+n+1);
	for(int i=1;i<=k;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
