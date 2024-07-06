#include<bits/stdc++.h>
using namespace std;
void jzzh(int n,int j){
	if(n==0) return;
	cout<<n%j;
	jzzh(n/j,j);
} 
int main(){
	jzzh(18,2);
	return 0; 
}
