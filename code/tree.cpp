#include<bits/stdc++.h>
using namespace std;
int t[10005],L,M,x,y,ans;
int main(){
	cin >> L >> M;
	for(int i = 1;i <= M;i++){
		cin >> x >> y;
		for(int j = x;j <= y;j++)
			t[j] = 1;
	}
	for(int i = 0;i <= L;i++)
		if (t[i] == 0) ans++;	
	cout << ans << endl;
	return 0;
}
