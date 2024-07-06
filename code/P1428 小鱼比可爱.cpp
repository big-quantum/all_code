#include<bits/stdc++.h>
using namespace std;
int n,a[105][2];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(a[i][0]>a[j][0]) a[i][1]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i][1]<<" ";
	}
	cout<<endl;
	return 0;
} 
