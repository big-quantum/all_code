#include<bits/stdc++.h>
using namespace std;
struct node {
	int len,d,id;
};
node p[1005];
bool mycmp(node x,node y) {
	if (x.len > y.len)
		return true;
	if (x.len == y.len && x.d < y.d)
		return true;
	if (x.len == y.len && x.d == y.d && x.id > y.id)
		return true;
	return false;
}
int n;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> p[i].len >> p[i].d >> p[i].id;
	sort(p + 1,p + 1 + n,mycmp);
	cout << p[1].id << endl;
	return 0;
}
