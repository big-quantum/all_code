#include<bits/stdc++.h>
using namespace std;
int m,s,t,sr,sm;
int main(){
	cin>>m>>s>>t;
	for(int i=1;i<=t;i++){
		sr+=17;
		if(m<10) m+=4;
		else {
			m=m-10;
			sm+=60;
		}
		if(sm>=sr) sr=sm;
		if(sr>=s){
			cout<<"Yes"<<endl;
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	cout<<sr<<endl;
	return 0; 
} 
