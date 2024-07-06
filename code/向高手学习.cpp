#include<bits/stdc++.h>
using namespace std;
int n,num[1005];
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> num[i];
	for(int i = 1;i <= n;i++){//找比每个数大且最小的位置 
		int ans = 0,tmp = 1000005;
		for(int j = 1;j <= n;j++)
		   if (num[j] > num[i] && num[j] < tmp){
		   	  tmp = num[j];
		   	  ans = j;
		   }
		cout << ans << endl;
	}
	return 0;
}

