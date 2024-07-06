#include <bits/stdc++.h>
using namespace std;
int n;
long long floor(int n){
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	return floor(n-1)+floor(n-2)+floor(n-3);
}
int main(){
	//freopen("floor.in","r",stdin);
	//freopen("floor.out","w",stdout);
	cin>>n;
	cout<<floor(n);
	return 0;
} 
