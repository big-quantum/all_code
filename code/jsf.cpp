#include<bits/stdc++.h>
using namespace std;
#define Maxn 100 + 5
int n,m,s[Maxn],i,j,t;
int main() {
	cin >> n >> m;
	for(i = 1; i <= n; i++)
		s[i] = 1;//每个座位上有人，第i个座位上的人为i
	i = 0;
	t = n;//t为没出圈的人
	while(t) {
		i++;
		if (i == n + 1)
			i = 1;
		if (s[i]) {
			j++;
			if (j == m) {
				cout << i << " ";
				s[i] = 0;
				j = 0;
				t--;
			}
		}
	}
	return 0;
}
