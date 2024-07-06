#include<bits/stdc++.h>
using namespace std;
int n,num[105];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	} 
	for(int i=1;i<n;i++){ 
		for(int j=i+1;j<=n;j++){ 
			if (num[i]>num[j]){ 
				swap(num[i],num[j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<num[i]<<" ";
	}
	return 0;	
}

