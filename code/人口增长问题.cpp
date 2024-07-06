#include<bits/stdc++.h>
using namespace std;
double x,n;
int main(){
	cin>>x>>n;
	for(int i=1;i<=n;i++)
		x=x+x*0.001;
	cout.setf(ios::fixed);
	cout<<fixed<<setprecision(4)<<x<<endl;
	return 0;
}
