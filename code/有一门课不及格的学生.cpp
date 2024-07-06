#include<bits/stdc++.h>
using namespace std;
int a,b;
int main(){
	cin >> a >> b;
	if (a >= 60 && b < 60 || a < 60 && b >= 60) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}
