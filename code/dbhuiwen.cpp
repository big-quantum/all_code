#include<bits/stdc++.h>
using namespace std;
int a[100],b[100];
void jinzhi(int a,int w,int ch[]){
	int b=0,c=0;
	while(a){
 		ch[++c]=a%w;
 		a=a/w;
 	 	}
 	   ch[0]=c;
   }
bool check(int n[]){
	int len=n[0];
	for(int i=1;i<=len/2;i++){
		if(n[i]!=n[len+1-i]) return false;
	}	
	return true;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		jinzhi(i,10,a);
		jinzhi(i,2,b); 
		if(check(a)&&check(b)){
			cout<<i<<":";
			for(int j=b[0];j>0;j--){
				cout<<b[j];
			}
			cout<<endl;
		} 
	}	
	return 0;
} 
