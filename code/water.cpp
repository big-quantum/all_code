#include<bits/stdc++.h>
using namespace std;
int n,t[5][1005],ti;
float ts;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[0][i];
		t[1][i]=i;
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			if(t[0][j]>t[0][j+1]){
				swap(t[0][j],t[0][j+1]);
				swap(t[1][j],t[1][j+1]) ;
			}
		} 
	}
	for(int i=1;i<=n;i++){
		cout<<t[1][i]<<" ";
	}
	cout<<endl; 
	for(int i=1;i<=n;i++){
		ts+=t[0][i]*(n-i);
	}	
	ts=ts*1.00/10;
	cout<<fixed<<setprecision(2)<<ts<<endl;
	return 0;
}
