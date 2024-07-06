#include<bits/stdc++.h>
using namespace std;
struct pp {
	int cd,zc,bh;
};
pp a[1005];
int n;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].cd >> a[i].zc >> a[i].bh;
	for(int i = 1; i < n; i++)
		for(int j = i + 1; j <= n; j++)
			if (a[i].cd < a[j].cd || a[i].cd ==  a[j].cd && a[i].zc > a[j].zc || a[i].cd ==  a[j].cd && a[i].zc == a[j].zc && a[i].bh < a[j].bh)
				swap(a[i],a[j]);
	cout << a[1].bh << endl;
	return 0;
}
