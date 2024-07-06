#include<bits/stdc++.h>
using namespace std;
stack <int> st;
long long a,ans;
char b;
int main(){
	for(int i=1;;i++){
		if(i&1){
			cin>>a;
			st.push(a%10000);
			a=0;
		} else {
			b=getchar();
			if(b!='*'&&b!='+') break;
			if(b=='*'){
				cin>>a;
				int c=st.top();
				st.pop();
				st.push((c%10000)*(a%10000)%10000);
				i++;
			}
		}
	}
	while(!st.empty()){
		ans+=st.top();
		st.pop();
		ans=ans%10000;
	}
	cout<<ans<<endl;
	return 0;
}
