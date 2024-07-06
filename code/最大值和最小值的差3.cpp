#include<bits/stdc++.h>
using namespace std;
int m,num[10005],maxnum,minnum;
int main() {
	cin >> m;
	for(int i = 1;i <= m;i++)
		cin >> num[i];

	for(int i = 1;i < m;i++)
		for(int j = 1;j <= m - i;j++)
			if (num[j] > num[j + 1])
				swap(num[j],num[j + 1]);

	cout << num[m] - num[1] << endl;
	return 0;
}

