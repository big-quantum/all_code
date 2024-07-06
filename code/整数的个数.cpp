#include<bits/stdc++.h>
using namespace std;
short k[105],n,ten,five,one;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>k[i];
	for(int i=1;i<=n;i++){
		if(k[i]==1) one++;
		if(k[i]==10) ten++;
		if(k[i]==5) five++;
	}
	cout<<one<<endl;
	cout<<five<<endl;
	cout<<ten<<endl;
	return 0;
}
