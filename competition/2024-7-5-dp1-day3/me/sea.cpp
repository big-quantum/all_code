#include<bits/stdc++.h>//0
using namespace std;
const int mod = 998244353;
//蓝桥杯gcd/lcm问题
int x, y, n, q;

int prime[10005], cnt;
bool is_prime[1000005];

void init(){//求素数
    memset(is_prime, true, sizeof(is_prime));
    prime[++cnt] = 2;
    for(int j = 2; j <= 1005; j++){
        if(is_prime[j]){
            prime[++cnt] = j;
            for(auto i : prime){
                is_prime[i * j] = false;
            }
        }
    }
}

int main(){
    freopen("sea.in", "r", stdin);
    freopen("sea.out", "w", stdout);
    cin >> q;
    init();
    while(q--){
        cin >> x >> y >> n;
        long long num = y / x, numm;
        numm = num;
        long long cntnum = 0, i = 1;
        while(num != 1){
            while(num % prime[i] == 0){
                cntnum++;
                num /= prime[i];
            }
            i++;
        }
        cout << i * n / 2 % mod << endl;;
    }
    return 0;
}