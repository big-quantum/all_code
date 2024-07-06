#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	int r;
	while(b){
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int gcp(int a,int b,int c){
	return a*b/c; 
}
int main(){
	int x,y,ans=0,a;
	cin>>x>>y;
	for(int p=x;p<=y;p+=x){
		for(int q=x;q<=y;q+=x){
			a=gcd(p,q);
			if(a==x&&gcp(p,q,a)==y) ans++;
		}
	}
	cout<<ans<<endl; 
}
