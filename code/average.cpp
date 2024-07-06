#include<bits/stdc++.h>
using namespace std;
int n;
double a[25];
int main(){

	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i < n;i++){
		sort(a + i,a + 1 + n);
		a[i + 1] = (a[i] + a[i + 1]) / 2;
	}
	printf("%0.6lf\n",a[n]);
	return 0;
}
