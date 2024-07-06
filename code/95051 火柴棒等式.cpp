#include<bits/stdc++.h>
using namespace std;
int n,num[10]={6,2,5,5,4,5,6,3,7,6},ans;
int tmp[3005];
void left(){
	int temp=0;
	for(int i=0;i<=3000;i++){
		int a=i;
		do{
			temp+=num[a%10];
			a/=10;
		} while(a!=0);
		//cout<<temp<<" ";
		tmp[i]=temp;
		temp=0;
	}
}
int main(){
	cin>>n;
	n-=4;
	left();
	//for(int i=1;i<=1200;i++) cout<<tmp[i]<<" ";
	for(int i=0;i<=1200;i++){
		for(int j=0;j<=1200;j++){
			int temp=i+j;
			if(tmp[i]+tmp[j]+tmp[temp]==n) {
				ans++;
				//cout<<i<<" "<<j<<" "<<temp<<" "<<tmp[i]<<" "<<tmp[j]<<" "<<tmp[temp]<<endl;
				//cout<<tmp[temp]<<endl;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
