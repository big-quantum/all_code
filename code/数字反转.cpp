#include<bits/stdc++.h>
using namespace std;
int n,newnum;
int main(){
	cin>>n;
	while(n){
		newnum=newnum*10+n%10;
		n=n/10;
	}
	cout<<newnum;
	return 0;
}
