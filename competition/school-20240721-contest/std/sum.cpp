#include<bits/stdc++.h>

using namespace std;

string addBinary(string a, string b) {
    string ans;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int n = max(a.size(), b.size()), carry = 0;
    for (size_t i = 0; i < n; ++i) {
        carry += i < a.size() ? (a.at(i) == '1') : 0;
        carry += i < b.size() ? (b.at(i) == '1') : 0;
        ans.push_back((carry % 2) ? '1' : '0');
        carry /= 2;
    }

    if (carry) {
        ans.push_back('1');
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);

    string a, b;
    cin >> a >> b;
    cout << addBinary(a, b) << "\n";

    fclose(stdin);
    fclose(stdout);

    return 0;
}