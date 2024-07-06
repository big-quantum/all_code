#include<bits/stdc++.h>
using namespace std;
int n,minn,a;
int main(){
	cin>>n;
	cin>>minn; 
	for(int i=1;i<=n-1;i++){
		cin>>a;
		if(a<minn) minn=a;
	}
	cout<<minn<<endl;
	return 0;
} 
