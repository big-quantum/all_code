#include<bits/stdc++.h>
using namespace std;
int number,n,ans;
bool number2[1005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>number;
		number2[number]=true; 
	}
	for(int i=1;i<=1003;i++)
		if(number2[i]==true)
			ans++;
	cout<<ans<<endl;
	for(int i=1;i<=1003;i++)
		if(number2[i]==true)
			cout<<i<<" ";
	return 0; 
}