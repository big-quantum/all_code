#include<bits/stdc++.h>
using namespace std;
int n;
long long jc(int n){
	if(n==0)
		return 1;
	else
		return n*jc(n-1);
}
int main(){
	cin>>n;
	cout<<jc(n)<<endl;
	return 0;
}	 
