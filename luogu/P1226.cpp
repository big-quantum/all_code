#include<bits/stdc++.h>
using namespace std;
//quickpower
long long a, b, p, ans = 1, bb;

int main(){
	
	cin >> a >> b >> p;
	bb = b;
	long long pow = a;
	while(b > 0){
		if(b & 1){
			ans *= pow;
			ans %= p;
		}
		pow *= pow;
		pow %= p;
		b >>= 1; 
	}
	ans %= p;
	printf("%lld^%lld mod %lld=%lld", a, bb, p, ans);
	return 0;
}
