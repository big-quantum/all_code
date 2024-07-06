#include<bits/stdc++.h>
using namespace std;
int s,i,n,t,k,r,w[100001],x[300002],y[300002];
int main(){
    cin>>n;
    while(n--){
        cin>>t>>k;
        while(k--){
            y[++r]=t;
			cin>>x[r];
            if(!w[x[r]])s++;
            w[x[r]]++;
        }
        while(t-y[i]>=86400){
        	w[x[i]]--;
        	if(!w[x[i]]) s--;
        	i++;
 		}
        cout<<s<<endl;
    }
}
