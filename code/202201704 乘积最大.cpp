#include<bits/stdc++.h>
using namespace std;
long long n,numa,numb;
int number[15],leng;
bool cmp(int a,int b){
	if(a>b) return true;
	return false;
}
int out(int a){
	int k=1;
	while(a!=0){
		number[k]=a%10;
		a=a/10;
		k++;
	}
	return k-1;
}
int main(){
	cin>>n;
	leng=out(n);
	sort(number+1,number+12,cmp);
	for(int i=1;i<=leng/2;i++){
		if(i%2==1){
			numa=numa*10+number[i*2-1];
			numb=numb*10+number[i*2];
		} else {
			numb=numb*10+number[i*2-1];
			numa=numa*10+number[i*2];
		}
	}
	if(leng%2==1){
		if(numa>numb) numb=numb*10+number[leng];
		else numa=numa*10+number[leng];
	}
	cout<<numa*numb<<endl;
	return 0;
}
