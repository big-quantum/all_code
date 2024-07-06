#include<bits/stdc++.h>
using namespace std;
int t[10005],L,M,x,y,ans;
int main(){
	cin >> L >> M;
	for(int i = 0;i <= L;i++)
		t[i] = 1;
	for(int i = 1;i <= M;i++){
		cin >> x >> y;
		for(int j = x;j <= y;j++)
			t[j] = 0;
	}
	for(int i = 0;i <= L;i++)
		ans = ans + t[i];
	cout << ans << endl;
	return 0;
}
