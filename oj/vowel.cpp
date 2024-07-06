#include<bits/stdc++.h>
using namespace std;

int n, ans[10005], m;
string s[10005];
char yuan[5] = {'a', 'e', 'i', 'o', 'u'};

bool check(char s) {
    return s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u';
}

int main(){
    freopen("vowel.in", "r", stdin);
    freopen("vowel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];

        int length = s[i].size();
        ans[i] = ans[i] + ans[i - 1];
        if(length < 2) continue;
        if(check(s[i][1]) && check(s[i][length - 2])) ans[i]++;
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        int from, end;
        cin >> from >> end;

        if(from == end && ans[from + 1] != ans[from]) cout << 1 << " ";
        if(from == 0) cout << ans[end + 1] << " ";
        else cout << ans[end + 1] - ans[from + 1] << " "; 
    }

    return 0;
}