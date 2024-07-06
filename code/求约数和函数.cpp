#include<bits/stdc++.h>
using namespace std;
int ysh(int n){
	int i,s=0;
	for(i=1;i*i<=n;i++) {
		if(n%i==0)
			if(i*i==n)
				s+=i;
			else
				s+=i+n/i;
	}
	return s-n;
}
