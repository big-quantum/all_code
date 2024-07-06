#include<bits/stdc++.h>
using namespace std;
int m,num[10005],maxnum,minnum;
int main() {
	cin >> m;
	for(int i = 1;i <= m;i++)
		cin >> num[i];
	maxnum = num[1];
	minnum = num[1];

	for(int i = 2; i <= m; i++) {	
		if (num[i] > maxnum)
			maxnum = num[i];
		if (num[i] < minnum)
			minnum = num[i];
	}
	cout << maxnum - minnum << endl;
	return 0;
}

