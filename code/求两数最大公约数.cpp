#include<bits/stdc++.h>
using namespace std;

int m,n,ans;
int gcd(int x,int y){
	if (x % y == 0)
		return y;
	else
		return gcd(y,x % y);
}
int main(){
	cin >> m >> n;
	ans = gcd(m,n);
	cout << ans << endl;
	return 0;
} 
/*
	m     n     r
	24    36    24
	36    24    12
	24    12    0
	欧几里德辗转相除法求最大公约数

*/ 
