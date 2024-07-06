#include<bits/stdc++.h>
using namespace std;
int dx(int n){
	int s=0;
	while(n){
		s=s*10+n%10;
		n/=10;
	}
	return s;
}
