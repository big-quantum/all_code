#include<bits/stdc++.h>
using namespace std;
int n,x,h,l,k,s;
int main(){
	cin>>n>>x;
	while(s<x){
		k++;
		s+=k;
	}
	if(k%2==0){
		l=s-x+1;
		h=k+1-l;
	} else {
		h=s-x+1;
		l=k+1-l;
	}
	if(x<=(n*(n+1))/2) cout<<h<<" "<<l<<endl;
	else cout<<n+1-h<<" "<<n+1-l<<endl;
	return 0;
} 
