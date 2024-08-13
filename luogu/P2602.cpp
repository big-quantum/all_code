#include<bits/stdc++.h>
using namespace std;

long long a, b, ansa[10], ansb[10], f[20], _pow[20];


void solve(long long num, long long cnt, long long *ans){
    if(cnt == 0) return;
    int fr = num / _pow[cnt - 1];
    for(int i = 0; i <= 9; i++){
        ans[i] += f[cnt - 1] * fr;
        if(i < fr) ans[i] += _pow[cnt - 1];
        if(i == fr) ans[i] += num % _pow[cnt - 1] + 1;
    }
    ans[0] = ans[0] - _pow[cnt - 1];
    solve(num % _pow[cnt - 1], cnt - 1, ans);
}

int main(){
    f[1] = 1;
    _pow[0] = 1;
    _pow[1] = 10;
    for(int i = 2; i <= 13; i++){
        _pow[i] = _pow[i - 1] * 10;
        f[i] = f[i - 1] * 10 + _pow[i - 1];
    }
    cin >> a >> b;
    long long cnta = 0, cntb = 0, numa = a - 1, numb = b;
    while(numa != 0){
        cnta++;
        numa /= 10;
    }
    while(numb != 0){
        cntb++;
        numb /= 10;
    }
    solve(a - 1, cnta, ansa);
    solve(b, cntb, ansb);
    for(int i = 0; i <= 9; i++){
        cout << ansb[i] - ansa[i] << " ";
    }
    return 0;
}