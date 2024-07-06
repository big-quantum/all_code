#include<bits/stdc++.h>
using namespace std;

int num[30005],s[30005],n,ans = 30005;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> num[i];
		num[i]--;
		s[i] = s[i - 1] + num[i];
	}
	for(int i = 1;i <= n;i++)
		if (s[i - 1] + n - i + 1 - (s[n] - s[i - 1]) < ans)
			ans = s[i - 1] + n - i + 1 - (s[n] - s[i - 1]);
	ans = min(ans,s[n]);
	ans = min(ans,n - s[n]);
	cout << ans << endl;
	return 0;
}




