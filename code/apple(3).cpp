#include<bits/stdc++.h>
using namespace std;
int n,a[10005],sum,ave,ans;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum += a[i];		
	}
	ave = sum / n;
	for(int i = 1;i <= n;i++)
		if (a[i] < ave)
			ans = ans + ave - a[i];
	cout << ans << endl;
	return 0;
} 
