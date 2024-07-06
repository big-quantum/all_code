#include<bits/stdc++.h>
using namespace std;
int n, num[505], t;
int main() {
    cin >> t;
    cin >> n;
    while (t != 0) {
        int num_dif = 0x3f3f3f3f, s, ans = 0;
        for(int i = 1; i <= n; i++) {
            cin >> num[i];
            if(num[i - 1] > num[i]) {
                cout << 0 << endl;
                t--;
                continue;
            }
            if(num[i] - num[i - 1] < num_dif) {
                num_dif = num[i] - num[i - 1]; 
                s = i - 1;
            }
        }
        while (num[s] <= num[s + 1]) {
            for(int i = 1; i <= s; i++) {
                num[i]++;
            }
            for(int i = s + 1; i <= n; i++) {
                num[i]--;
            }
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}