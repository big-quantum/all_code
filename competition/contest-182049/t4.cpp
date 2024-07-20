#include<bits/stdc++.h>
using namespace std;

int n, m, maxn, pos, a[10005], b[10005];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        b[tmp]++;
    }
    for(int i = 1; i <= m; i++){
        if(maxn < a[i] * b[i]){
            maxn = a[i] * b[i];
            pos = i;
        }
    }
    cout << pos << endl;
    return 0;
}