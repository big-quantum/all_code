#include<bits/stdc++.h>
using namespace std;
int a,c,r,maxans,minans;
bool suc = false;
int main(){ 
	cin >> a;
	minans = a;
	for(int i = 0;i <= a / 2;i++){
		int j = (a - i * 2) / 4;
		if (i * 2 + j *4 == a){
			maxans = max(maxans,i + j);
			minans = min(minans,i + j);
			suc = true;
		}
		
	}
	if (suc) cout << minans << " " << maxans << endl;
	else cout << 0 << " " << 0 << endl;
	return 0;
}
