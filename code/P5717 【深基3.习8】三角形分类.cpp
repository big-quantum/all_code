#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	cin>>a>>b>>c;
	if(a>b)
		swap(a,b);
	if(a>c)
		swap(a,c);
	if(b>c)
		swap(b,c);
	if(a+b>=c&&b+c>=a&&a+c>=b){
		if(a*a+b*b==c*c) cout<<"Right triangle"<<endl; 
		if(a*a+b*b>c*c) cout<<"Acute triangle"<<endl; 
		if(a*a+b*b<c*c) cout<<"Obtuse triangle"<<endl;
		if(a==b||b==c||a==c) cout<<"Isosceles triangle"<<endl; 
		if(a==b&&b==c) cout<<"Equilateral triangle"<<endl; 
	}
	else cout<<"Not triangle"<<endl; 
	return 0;	
}

