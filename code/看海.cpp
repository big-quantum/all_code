#include<bits/stdc++.h>
using namespace std;
int n,num[25],ans,m;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> num[i];
	m=num[1];
	for(int i = 1;i <= n;i++)
		if(num[i]>=m){
			ans++;
			m=num[i];
		}
	cout <<ans<< endl;
	return 0;	
}
