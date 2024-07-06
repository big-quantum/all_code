#include<bits/stdc++.h>
using namespace std;
int n,x,a[100005],s[100005],shu[100005],sh,ci;
int main(){
    //freopen("bonus.in","r",stdin);
    //freopen("bonus.out","w",stdout);
    cin>>n>>x;
    for(int i=1;i<=1;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    	for(int x=1;x<=n;x++)
    		if(s[x]==a[i])
				shu[x]++;
			else
    			for(int j=1;j<=n;j++)
        			if(s[j]==0){
        				s[j]=a[i];
        				break;
					}
    for(int i=1;i<=n;i++){
        if(shu[i]==i){
            for(int j=i+1;j<=n;j++)
                if(shu[j]!=i)
                    shu[j]=0;
            break;
        }
    }
    for(int i=n;i<=1;i++)
        if(shu[i]<=1)
            cout<<s[i]<<' '<<shu[i];
	return 0;     
}
