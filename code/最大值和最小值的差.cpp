#include<bits/stdc++.h>
using namespace std;
int m,num,maxnum,minnum;
int main() {
	cin >> m;
	cin >> num;
	maxnum = num;
	minnum = num;
	for(int i = 2; i <= m; i++) {
		cin >> num;
		if (num > maxnum)
			maxnum = num;
		if (num < minnum)
			minnum = num;
	}
	cout << maxnum - minnum << endl;
	return 0;
}

