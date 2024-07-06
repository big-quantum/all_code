#include<bits/stdc++.h>
using namespace std;
int l,a,b,c,d;
double n;
int main(){

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l;
		if((l>0) && (l<=18))
		a++;
		if((l>=19) && (l<=35))
		b++;
		if((l>=36) && (l<=60))
		c++;
		if((l>=61) && (l<=100))
		d++;
	}
	cout<<fixed<<setprecision(2)<<a/n*100.0;
	cout<<"%"<<endl;
	cout<<fixed<<setprecision(2)<<b/n*100.0;
	cout<<"%"<<endl;
	cout<<fixed<<setprecision(2)<<c/n*100.0;
	cout<<"%"<<endl;
	cout<<fixed<<setprecision(2)<<d/n*100.0;
	cout<<"%"<<endl;
	return 0;
}
