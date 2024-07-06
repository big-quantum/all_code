#include<bits/stdc++.h>
using namespace std;

int n,jw,s[10005],ans[10005];
int main(){
	cin >> n;
	s[1] = 1;
	for(int i = 1;i <= n;i++){
		jw = 0;
		for(int j = 1;j <= 5000;j++){
			jw = jw + s[j] * i;
			s[j] = jw % 10;
			jw = jw / 10;
		}		
		jw = 0;
		for(int j = 1;j <= 5000;j++){
			jw = jw + s[j] + ans[j];
			ans[j] = jw % 10;
			jw = jw / 10;
		}
	}
	int j;
	for(j = 5000;j >= 1;j--)
		if (ans[j])
			break;
	for(int i = j;i >= 1;i--)
		cout << ans[i];
	cout << endl;
	return 0;
}
