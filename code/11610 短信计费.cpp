#include<bits/stdc++.h>
using namespace std;
double ans;
int n,num;
double check(int z){
	if(z<=70) return 0.1;
	else return check(z-70)+0.1;
} 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num;
		ans+=check(num);
	}
	cout<<fixed<<setprecision(1)<<ans<<endl;
	return 0;
}
