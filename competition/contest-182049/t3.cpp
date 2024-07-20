#include<bits/stdc++.h>
using namespace std;

int n, a[100005], b[100005], c[100005], d[100005];
int maxn = -1, maxx = -1, pos;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        c[i] = b[i] / a[i];
        d[i] = b[i] % a[i];
        if(maxn < c[i] || (maxn == c[i] && maxx < d[i])){
            maxn = c[i];
            maxx = d[i];
            pos = i;
        }
    }
    cout << pos << endl;
    return 0;
}