#include<bits/stdc++.h>
using namespace std;
int n;//dp[100005][8][8];//前i次配送, i - 1次送给1号楼/2号楼, i - 2次送给1号楼/2号楼
short a[100005];
int anum[1005], bnum[1005], cnta, cntb = 1;
long long ans;

int check(int a, int b, int c){
    if(a == b && b == c){
        return 1;
    }
    if((a == b && b != c) || (b == c && a != b) || (a == c && a != b)){
        return 2;
    }
    if(a != b && b != c && a != c){
        return 3;
    }
    return 0;
}

int main(){
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        char s;
        cin >> s;
        if(s == 'M') a[i] = 1;
        if(s == 'F') a[i] = 2;
        if(s == 'B') a[i] = 3;
    }
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    if(n == 2){
        if(a[1] == a[2]) cout << 2 << endl;
        if(a[1] != a[2]) cout << 3 << endl;
        return 0;
    }
    anum[1] = a[1];
    ans++;
    cnta = 2;
    anum[0] = a[1];
    for(int i = 2; i <= n; i++){
        //cout  << i << endl;
        if(anum[cnta - 1] != a[i]){
            ans += check(anum[cnta - 2], anum[cnta - 1], a[i]);
            //cout << i << " " << check(anum[cnta - 2], anum[cnta - 1], a[i]) << endl;
            anum[cnta++] = a[i];
            continue;
        } else {
            if(cntb == 1){
                bnum[cntb] = a[i];
                bnum[cntb - 1] = a[i];
                //cout << i << " " << 1 << endl;
                cntb++;
                ans++;
                continue;
            }
            if(bnum[cntb - 1] != a[i]){
                ans += check(bnum[cntb - 2], bnum[cntb - 1], a[i]);
                //cout << i << " " << check(anum[cnta - 2], anum[cnta - 1], a[i]) << endl;
                bnum[cntb++] = a[i];
                continue;
            } else {
                ans += check(anum[cnta - 2], anum[cnta - 1], a[i]);
                //cout << i << " " << check(anum[cnta - 2], anum[cnta - 1], a[i]) << endl;
                anum[cnta++] = a[i];
                continue;
            }
        }
    }
    cout << ans << endl;
    /*
    dp[1][0][0] = 1;//第1次送给1号楼
    dp[1][1][0] = 1;//第1次送给2号楼
    if(a[1] != a[2]) dp[2][0][0] = 2;//第2次送给1号楼,第1次送给1号楼,且不同
    else dp[2][0][0] = 1;//第2次送给1号楼,第1次送给1号楼,且相同
    if(a[1] != a[2]) dp[2][1][1] = 2;//第2次送给2号楼,第1次送给2号楼,且不同
    else dp[2][1][1] = 1;////第2次送给2号楼,第1次送给2号楼,且相同
    dp[2][1][0] = 2;//1,2两次分别送给1,2号楼
    dp[2][0][1] = 2;//1,2两次分别送给2,1号楼
    
    for(int i = 3; i <= n; i++){
        //送给一号楼
        dp[i][1][1] = max(dp[i - 1][0][1],)//前两次送给2号楼
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == 1){
            dp[i][4][]
        }
    }*/
    return 0;
}