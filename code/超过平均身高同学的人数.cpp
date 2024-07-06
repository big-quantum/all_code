#include<bits/stdc++.h>
using namespace std;
int t[1005],p,n,ans,j;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin>>t[i];
	for(int i = 1;i <= n;i++)
		j=j+t[i];
	j=j/n;
	for(int i = 0;i <= n;i++)
		if(t[i]>j) ans++;
	cout << ans << endl;
	return 0;
}
