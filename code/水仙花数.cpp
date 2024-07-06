#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c;
bool d;
int main(){
	cin>>n>>m;
	for(int i=n;i<=m;i++){
		a=i%10;
		b=i/10%10;
		c=i/100;
		if(a*a*a+b*b*b+c*c*c==i){
			d=true;
			cout<<i<<" "; 
		} 
	}
	if(d) cout<<endl;
	else cout<<"no"<<endl;
	return 0; 
} 
