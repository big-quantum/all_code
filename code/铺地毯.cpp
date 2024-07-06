#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[10001],b[10001],g[10001],k[10001];
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i]>>g[i]>>k[i];
        }
        int x,y;
        cin>>x>>y;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<=x&&a[i]+g[i]>=x&&b[i]<=y&&b[i]+k[i]>=y)ans=i+1;
        }
        if(ans==0)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
