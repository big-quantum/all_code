#include<bits/stdc++.h>
using namespace std;
int n;
double a[305],minnumber=999.0,maxnumber=-1.0,all,sum,numbermin,numbermax;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		all+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(minnumber>a[i]) minnumber=a[i];
		else if(maxnumber<a[i]) maxnumber=a[i];
	}
	all-=minnumber;
	all-=maxnumber;
	numbermin=minnumber;
	numbermax=maxnumber;
	sum=all*1.0/(n-2);
	maxnumber=-1.0;
	for(int i=1;i<=n;i++){
		if(a[i]!=numbermin&&a[i]!=numbermax&&abs(a[i]-sum)>maxnumber) maxnumber=abs(a[i]-sum);
	}
	printf("%.2f %.2f",sum,maxnumber);
	return 0;
}
