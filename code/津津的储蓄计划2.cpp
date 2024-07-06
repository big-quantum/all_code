#include<bits/stdc++.h>
using namespace std;
int q[13],s,shu,c;
int main(){
	for(int i=1;i<=12;i++)
	cin>>q[i];
	for(int i=1;i<=12;i++) {
		s=300+s;
		s=s-q[i];
		if(s<0) {
			cout<<'-'<<i<<endl; 
			break;
		}
		if(s>100) {
			shu=s/100;
			s=s-shu*100;
			c=c+shu*100;
		}
		if(i==12) cout<<c+c*0.2+s<<endl;
	}
	return 0;
} 
