#include<bits/stdc++.h>
using namespace std;
int n,k,ans,f=200,c,a=0;
int main(){
	cin>>n>>k;
	for(int i=1;i<=20;i++){
		ans=i;
		c=c+n;
		if(f<=c){
			cout<<ans<<endl;
		    a=1;
		    break;
		}
		f=f+f*0.01*k;
	}
	if(a!=1)
		cout<<"Impossible"<<endl;
	return 0;
}
