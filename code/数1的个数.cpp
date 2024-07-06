#include<bits/stdc++.h>
using namespace std;
int m,n,x;
int main(){
	cin>>m>>n>>x;
	while(x>0){ 
	if(x<ceil(m*1.0/n))
		break;
	x=x-ceil(m*1.0/n);
	n+=m/n; 
	}
	cout<<n; 
	return 0;
}
