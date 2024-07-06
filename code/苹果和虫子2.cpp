#include<bits/stdc++.h>
using namespace std;
int n,x,y,apple;
int main(){
	cin >> n >> x >> y;
	apple = y / x;
	if (y % x) apple++;
	if (n < apple) cout << 0 << endl;
	else cout << n - apple << endl;	
	return 0;
}
