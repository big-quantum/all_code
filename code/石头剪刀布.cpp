#include<bits/stdc++.h>
using namespace std;
int n,na,nb,a[1005],b[1005],fa,fb,la,lb,ansa,ansb;
int main(){
	cin>>n>>na>>nb;
	for(int i=0;i<na;i++)
		cin>>a[i]; 
	for(int i=0;i<nb;i++)
		cin>>b[i]; 
	la=na;
	lb=nb;
	for(int i=1;i<=n;i++){
		if(a[fa] == 0 && b[fb] == 2)
			ansa++;
		if(a[fa] == 2 && b[fb] == 5)
			ansa++;
		if(a[fa] == 5 && b[fb] == 0)
			ansa++;
		if(b[fb] == 0 && a[fa] == 2)
			ansb++;
		if(b[fb] == 2 && a[fa] == 5)
			ansb++;
		if(b[fb] == 5 && a[fa] == 0)
			ansb++;
		a[la]=a[fa];
		fa++;
		la++;
		b[lb]=b[fb];
		fb++;
		lb++;
	}
	if(ansa > ansb)
		cout<<"A"<<endl;
	if(ansa == ansb)
		cout<<"draw"<<endl;
	if(ansa < ansb)
		cout<<"B"<<endl;
	return 0;	
} 
