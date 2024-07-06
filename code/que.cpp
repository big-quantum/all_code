#include<bits/stdc++.h>
using namespace std;
int n,num[105],ans;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> num[i];
	for(int i = n - 1;i >= 1;i--)
		if (num[i] > num[i + 1]){
			ans = i;
			break;
		}
	cout << ans << endl;
	return 0;
} 

