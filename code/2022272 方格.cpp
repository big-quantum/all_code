#include<bits/stdc++.h>
using namespace std;
long long n,m,minn,x,y;
int main(){
	while(cin>>n>>m){
		minn=min(n,m);
		for(int i=0;i<=minn;i++){
			x=x+(m-i)*(n-i); 
		}
		y=n*(n+1)*m*(m+1)/4-x;
		cout<<x<<" "<<y<<endl;
		x=0;
		y=0;
	}
	return 0;
}
