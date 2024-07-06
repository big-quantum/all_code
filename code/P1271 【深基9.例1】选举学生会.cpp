#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],b;
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>b;
		a[b]++;
	}
	for(int i=1;i<=1000;i++){
		while(a[i]!=0){
			cout<<i<<" ";
			a[i]--;
		}
	}
	cout<<endl;
	return 0;
}
