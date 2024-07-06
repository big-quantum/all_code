#include<bits/stdc++.h>
using namespace std;
int a,s[15],b;
int main(){
	cin>>a;
	while(a){
		b=b*10+a%10;
		a=a/10;
	}
	cout<<b;
	return 0;
}
