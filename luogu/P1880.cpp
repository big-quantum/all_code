#include<bits/stdc++.h>
using namespace std;

int n, a[205];
long long dp1[205][205], s[205], dp2[205][205];

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i + n] = a[i];
	}
	for(int i = 1; i <= 2 * n; i++){
		s[i] = s[i - 1] + a[i];
	}
	
	for(int l = 1; l <= n * 2; l++){
		for(int r = 1; r <= n * 2; r++){
			if(l != r){
				dp1[l][r] = INT_MIN;
				dp2[l][r] = INT_MAX;
			}
		}
	}
	
	
	for(int len = 2; len <= n; len++){
		for(int l = 1; l + len - 1 <= n * 2 - 1; l++){
			int r = l + len - 1;
			for(int k = l; k < r; k++){
				dp1[l][r] = max(dp1[l][r], dp1[l][k] + dp1[k + 1][r] + s[r] - s[l - 1]);
				dp2[l][r] = min(dp2[l][r], dp2[l][k] + dp2[k + 1][r] + s[r] - s[l - 1]);
			}
		}
	}
	
	int ans_max = -1, ans_min = INT_MAX;
	
	for(int i = 1; i <= n; i++){
		if(dp1[i][i + n - 1] > ans_max) ans_max = dp1[i][i + n - 1];
		if(dp2[i][i + n - 1] < ans_min) ans_min = dp2[i][i + n - 1];
	}
	cout << ans_min << endl;
	cout << ans_max << endl;
	return 0;
}
