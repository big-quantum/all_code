#include<bits/stdc++.h>
using namespace std;
#define Maxn 100000
int n,t[Maxn + 5],ty,tc,ansy,ansc,lft,rgt;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> t[i];
	lft = 1;
	rgt = n;
	while(lft <= rgt)
		if (ty <= tc){
			ty = ty + t[lft];
			lft++;
			ansy++;
		}
		else {
			tc = tc + t[rgt];
			rgt--;
			ansc++;
		}
	cout << ansy << " " << ansc << endl;
	return 0;	
} 
