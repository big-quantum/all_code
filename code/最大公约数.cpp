#include<bits/stdc++.h>
using namespace std;
int m,n;
int gcd(int x,int y){

	if(x%y==0)
		return y;
	else
		return gcd(y,x%y);
}
int main(){
	cin>>m>>n;
	cout<<gcd(m,n)<<endl;
	return 0;
}	 
