#include<bits/stdc++.h>
using namespace std;
int a[20];
int rf(int x,int right,int left,int a[]){
	if(left<right) {
		return -1;
	}
	int mid=(right+left)/2;
	if(a[mid]>x) return rf(x,right,mid-1,a);
	else if(a[mid]<x) return rf(x,mid+1,left,a); 
		else {
			return mid;
		}
}
int main()
{
	int n,a[100],front,left,mid,x,re;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>x;
	front=1;
	left=n;
	re=rf(x,front,left,a);
	cout<<re;
	return 0;
}

