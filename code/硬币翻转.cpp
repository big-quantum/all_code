#include<bits.stdc++.h>
using namespace std;
int n,coin[105];
int main(){
	cin>>n;
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			if(i!=j)
				coin[j] = 1-coin[j];
				
	}
	return 0;
}
