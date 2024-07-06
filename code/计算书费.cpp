#include<bits/stdc++.h>
using namespace std;
float m[10] = {28.9,32.7,45.6,78,35,86.2,27.8,43,56,65};
float ans = 0;
int num;
int main() {
	for(int i = 0;i < 10;i++){
		scanf("%d",&num);
		ans = ans + num * m[i];
	}
	cout << ans << endl;
	return 0;
}
