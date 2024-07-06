#include<bits/stdc++.h>
using namespace std;
#define Maxn 100
int n,num[Maxn + 5],cnt;
int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&num[i]);
	for(int i = 1; i < n; i++)
		for(int j = i + 1; j <= n; j++)
			if (num[i] > num[j]) 
				swap(num[i],num[j]);
	for(int i = 1; i < n; i++)
		for(int j = i + 1; j <= n; j++)	
			if (num[i] == num[j]) 
				num[j] = -1;
	for(int i = 1;i <= n;i++)
		if (num[i] != -1) cnt++;
	cout << cnt << endl;			
	for(int i = 1; i <= n; i++)
		if (num[i] != -1) cout << num[i] << " ";

	return 0;
}

