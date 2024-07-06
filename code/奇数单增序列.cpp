#include<bits/stdc++.h>
using namespace std;
#define Maxn 505
int n,num[Maxn],t,number;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> number;
		if (number % 2){
			t++;
			num[t] = number;
		}		
	}	
	for(int i = 1;i < t;i++)
		for(int j = i + 1;j <= t;j++)
			if (num[i] > num[j])
				swap(num[i],num[j]);
	for(int i = 1;i < t;i++)
		cout << num[i] << ",";
	cout << num[t] << endl;
	return 0;
}
