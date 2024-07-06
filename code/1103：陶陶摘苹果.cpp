#include<bits/stdc++.h>
using namespace std;
int hight,apple[15],ans;
int main(){
	for(int i=1;i<=10;i++){
		cin>>apple[i];	
	}
	cin>>hight;
	hight+=30; 
	for(int i=1;i<=10;i++){
		if(hight>=apple[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
