#include<bits/stdc++.h>
using namespace std;
int n,a1,a2;
float a[305],minnumber=999.0,maxnumber=-1.0,all,sum,numbermin,numbermax;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		all+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(minnumber>a[i]) {
			minnumber=a[i];
			a1=i;
		}
		else if(maxnumber<a[i]){
			maxnumber=a[i];
			a2=i;
		}
	}
	all-=minnumber;
	all-=maxnumber;
	sum=all*1.0/(n-2);
	maxnumber=-1.0;
	for(int i=1;i<=n;i++){
		if(i!=a1&&i!=a2&&fabs(a[i]-sum)>maxnumber) maxnumber=fabs(a[i]-sum);
	}
	printf("%.2f %.2f",sum,maxnumber);
	return 0;
}
