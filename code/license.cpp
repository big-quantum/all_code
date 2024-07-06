#include<bits/stdc++.h>
using namespace std;
int t,num[500005];
string s;
int main(){
	freopen("license.in","r",stdin);
	freopen("license.out","w",stdout);
	while(cin >> s){
		t++;
		int x = 0;
		for(int i = 2;i <= 6;i++){
			if (s[i] >= '0' && s[i] <= '9')
				x = x * 36 + s[i] -'0';	
			if (s[i] >= 'A' && s[i] <= 'Z')
				x = x * 36 + s[i] - 55;				
		}
		num[t] = x;
	}
	sort(num + 1,num + 1 + t);
	int ans = num[t] - num[1];
	for(int i = 2;i <= t;i++)
		ans = min(ans,num[i] - num[i - 1]);
	cout << ans << endl;
	return 0;
}

/*
123
x
0  0*10+1=1
   1*10+2=12
   12*10+3=123

*/
