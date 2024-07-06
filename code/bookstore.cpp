#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],n,m;
int main(){
	int low,high,mid;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=m;i++){
		low=1;
		high=n;
		while(low<=high&&a[mid]!=b[i]){
			mid=(low+high)/2;
			if(a[mid]>b[i]) high=mid-1;
			else low=mid+1; 
		}
		if(a[mid]==b[i]) cout<<"Y";
		else cout<<"N";
	}
	return 0;
}
