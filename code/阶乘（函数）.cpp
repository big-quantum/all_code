#include<bits/stdc++.h>
using namespace std;
int fac(int x){
	int s=1; 
	for(int i=1;i<=x;i++) s=s*i;
	return s; 
} 
int main(){
	cout<<fac(3)+fac(5)+fac(14)<<endl; 
}
