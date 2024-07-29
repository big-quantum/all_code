#include<bits/stdc++.h>
using namespace std;

int n, d, v[100005], a[100005], mina[100005];
long long ans, dis;

int main(){
	cin >> n >> d;
	mina[0] = INT_MAX;
	for(int i = 1; i <= n - 1; i++){
		cin >> v[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mina[i] = min(mina[i - 1], a[i]);
	}
	for(int i = 2; i <= n; i++){
		dis += v[i - 1];
		if(dis > 0){
			long long ll = dis / d;
			if(dis % d != 0){
				ll++;
				dis = dis % d - d;
			} else dis = 0;
			ans += ll * mina[i - 1];
		}
	}
	cout << ans << endl;
	return 0;
}
