#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,a1,b1,c1,d1,tmp,m1,m2,l;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	cin>>a>>b>>c>>d;
	a1=a;
	b1=b;
	c1=c;
	d1=d;
	while(tmp=a%b){
		a=b;
		b=tmp;
	}
	tmp=-1;
	m1=a1*b1/b;
	cout<<m1<<" ";
	while(tmp=c%d){
		c=d;
		d=tmp;
	}
	tmp=-1;
	m2=c1*d1/d;
	cout<<m2<<endl; 
	while(tmp=m1%m2){
		m1=m2;
		m2=tmp;
	}
	cout<<m2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
