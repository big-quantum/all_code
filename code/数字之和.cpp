#include<bits/stdc++.h>
using namespace std;
int n,s,num;
int main(){
	cin>>n;
	num=n;
	while(num){
		if(num<10)s=s+num;
		else s=s+num%10;
		num=num/10;
	}
	if(n%s==0)cout<<"YES";
	else cout<<"NO";
	return 0;
}
