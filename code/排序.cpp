#include<bits/stdc++.h>
using namespace std;
#define Maxn 100
int num[Maxn + 5],n;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> num[i];
	sort(num + 1,num + 1 + n);
	for(int i = 1;i <= n;i++)
		cout << num[i] << " ";
	cout << endl;
	return 0;	
}
