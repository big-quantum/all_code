#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k[105], c[105], dp[20005];

signed main(){
	cin >> n >> m;
    int r = 0;
    for(int i = 1; i <= n; i++){
        cin >> k[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        r += c[i] * k[i];
    }
	dp[0] = 1;
    for(int i = 1; i <= n; i++){
	    for(int j = r; j >= c[i]; j--){
	        for(int z = 1; z <= k[i] && c[i] * z <= j; z++){
	            dp[j] = max(dp[j], dp[j - c[i] * z] * z);
	        }
        }
    }
    for(int i = 0; i <= r; i++){
        if(dp[i] >= m){
	        cout << i << endl;
			break;	
		}
    }
	return 0;
}
