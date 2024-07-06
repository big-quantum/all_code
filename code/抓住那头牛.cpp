#include<bits/stdc++.h>
using namespace std;
bool vis[100005];
int lr[2]={-1,1},n,k;
struct node{
    int x,step;
}road[1000005];
void bfs(int n,int k){
    int first=1,last=1;
    vis[n]=1;
    road[last].x=n;
    road[last].step=0;
    last++;
    while(first<last){
        int x=road[first].x;
        int step=road[first].step;
        if(x==k){
            cout<<step<<endl;
            break;
        }
        int tx;
        for(int i=0;i<2;i++){
            tx=x+lr[i];
            if(0<=tx&&tx<100005&&vis[tx]==0){
                vis[tx]=1;
                road[last].x=tx;
                road[last].step=step+1;
                last++;
            }
        }
        tx=x*2;
        if(tx>=0&&tx<100005&&vis[tx]==0){
            vis[tx]=1;
            road[last].x=tx;
            road[last].step=step+1;
            last++;
        }
        first++;
    }
}
int main(){
    cin>>n>>k;
    if(k<n){
        cout<<n-k<<endl;
        return 0;
    }
    bfs(n,k);
    return 0;
}
