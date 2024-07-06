#include<bits/stdc++.h>
using namespace std;
int n;
long long zlt(int n){
	if(n<3)
		return n;
	else
		return zlt(n-1)+zlt(n-2);
}
int main(){
	cin>>n;
	cout<<zlt(n)<<endl;
	return 0;
}
