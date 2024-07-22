#include<bits/stdc++.h>
using namespace std;

int n, tmp[10005], a[105][105], b[10005], c[10005];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        for(int j = 1; j <= b[i]; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= b[i]; j++){
            c[i] += b[a[i][j]];
        }
        c[i] += b[i];
    }
    for(int i = 1; i <= n; i++){
        cout << c[i] << " ";
    }
    return 0;
}