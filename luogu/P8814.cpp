#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t, n, e, d;
    cin >> t;
    while(t--){
        cin >> n >> e >> d;
        long long m = n - e * d + 2;
        if(m * m < 4 * n){
            cout << "NO" << endl;
            continue;
        } else {
            long long m0 = sqrt(m * m - 4 * n);
            long long p = (m0 + m) / 2;
            long long q = m - p;
            if(p > q) swap(p, q);
            if(n == p * q && e * d == (p - 1) * (q - 1) + 1) cout << p << " " << q << endl;
            else cout << "NO" << endl;
        }
    }


    return 0;
}