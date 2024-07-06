#include<bits/stdc++.h>
using namespace std;
vector<int>a[1005];
int n,sum;
int mian(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sum;
		a[i].push_back();
		for(j=1;j<=sum;j++){
			a[i].push_back()
		}
	}
	for(int i=1;i<=n;i++){
		sort(a[i].begin()+1,a[i].end());
		for(int j=1;j<=a[0];j++){
			cout<<a[j]<<" "；
		}
	}
	return 0;
}