#include<bits/stdc++.h>
using namespace std;
int n,a[10005],cnt;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
} 
