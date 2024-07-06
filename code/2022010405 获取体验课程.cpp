#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
bool check(int n){
	if(n<2) return false;
	for(int i=2;i<n;i++)
		if (n%i==0) return false;
	return true;
}
int main(){
	cin>>n;
	a=n%10;
	b=n%100/10;
	c=n/100;
	if(check(n)&&check(a)&&check(b)&&check(c)){
		cout<<"Yes!"<<endl;
	} else {
		cout<<"No!"<<endl;
	}
	return 0;
} 
