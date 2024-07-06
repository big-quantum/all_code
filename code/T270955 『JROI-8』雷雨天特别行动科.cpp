#include<bits/stdc++.h>
using namespace std;
long long x,k,n;
int main(){
	cin>>x>>k;
	n=x%3;
	if(x==0){
		k--;
		cout<<k%2+1<<endl;
		return 0;
	}
	if(k==0){
		cout<<x<<endl;
		return 0;
	}
	n=x%3; 
	for(int i=1;i<=k;){
		if(i+3<k&&n>0){
			x=x+3-n;
			x=x/3;
			i+=n;
		} else {
			x++;
			i++;
			n=x%3;
			if(!n) x=x/3;
		}
	} 
	cout<<x<<endl;
	return 0;
} 
