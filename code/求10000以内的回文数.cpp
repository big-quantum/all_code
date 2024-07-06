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
int main(){
	for(int i=1;i<=10000;i++){
		if(i==dx(i)){
			cout<<i<<" ";
		} 
	}
} 
