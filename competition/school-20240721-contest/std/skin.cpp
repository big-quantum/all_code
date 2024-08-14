#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 245000;

int n, p;
ll m;
int s[N], c[N];
ll dp[N];

int main() {
    freopen("skin.in", "r", stdin);
    freopen("skin.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i ++ ) {
        cin >> c[i], p += s[i] * c[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = p; j >= c[i]; j--) {
            for (int k = 1; k * c[i] <= j && k <= s[i]; k++) {
                dp[j] = max(dp[j], dp[j - k * c[i]] * k);
            }
        }
    }

    for (int i = 0; i <= p; i ++ ) {
        if (dp[i] >= m) {
            cout << i;
            break;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}