#include<bits/stdc++.h>
using namespace std;

int n, m, t[200006], ans;
int _time[2000005];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> t[i];
		for(int j = 1; j <= m; j++){
			_time[t[i] + j - 1]++;
		}
	}
	sort(t + 1, t + 1 + n);
	int flag1 = false, flag2 = false;
	if(m == 1){
		int tmp = 0;
		for(int i = 1; i <= n; i++){
			while(t[i + 1] == t[i]){
				tmp++;
				i++;
			}
			if(tmp == 0) ans++;
			if(tmp == 1) flag1 = true;
			if(tmp > 1) flag2 = true;
		}
		if(flag1) cout << ans + 2 << endl;
		else if(flag2) cout << ans + 1 << endl; 
		else cout << ans << endl;
		return 0;
	}
	
	
	int end = t[n] + m - 1;
	for(int i = 1; i <= end; i++){
		if(_time[i] == 1) ans++;
	}
	int ans1 = ans, tmp = ans;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			_time[t[i] + j - 1]--;
			if(_time[t[i] + j - 1] == 0) ans1--;
			if(_time[t[i] + j - 1] == 1) ans1++;
			_time[t[i] + j - 1]++;
		}
		ans = max(ans1, ans);
		ans1 = tmp;
	}
	cout << ans + m << endl;
	return 0;
}
