#include<bits/stdc++.h>
using namespace std;
int s[10],x[10],boss,t;
int main(){
	for(int i=1;i<=7;i++)
		cin>>s[i]>>x[i];
	for(int i=1;i<=7;i++){
		if(s[i]+x[i]>8)
			if(boss<s[i]+x[i]){
				boss=s[i]+x[i];
				t=i;
			}
	}
	cout<<t<<endl;
	return 0;
}
