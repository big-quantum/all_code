#include<bits/stdc++.h>
using namespace std;
int n,a[101],m,ans,i;
int main(){
	cin >> n;
	for(i=0;i<n;i++)
		cin >> a[i];
	cin >> m;
	for(i=0;i<n;i++)
		if(a[i] == m)
			ans++;
	cout << ans;
	return 0;
}
