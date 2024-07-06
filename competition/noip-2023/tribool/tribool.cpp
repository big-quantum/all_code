//until 10:30 I wish solve 1-8

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXN_PROMOT = 1005;
const int MINN_PROMOT = -1005;

int c, t;

int promot_check(char a){
    if(a == 'T') return 1;
    if(a == 'U') return 0;
    if(a == 'F') return -1;
    if(a == '-') return MINN_PROMOT;
    if(a == '+') return MAXN_PROMOT;
    return 0;
}

int opp(int a) {
    if(a == 1) return -1;
    if(a == -1) return 1;
    if(a == 0) return 0;
    return 0;
}

void mode_1(){
    int n, m, ans = 0;
    int step[15][3];
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        char promot;
        scanf("%c", &promot);
        int promot_num = promot_check(promot);
        if(promot_num == 1 || promot_num == 0 || promot_num == -1) {
            step[i][0] = promot_num;
            scanf("%d", &step[i][1]);
        }
        if(promot_num == MAXN_PROMOT || promot_num == MINN_PROMOT) {
            step[i][0] = promot_num;
            scanf("%d%d", &step[i][1], &step[i][2]);
        }
    }
    //cin_number
    
    bool flag = false;
    int test_num[15] = {1,-1,1,1,1,1,1,1,1,1,1,1}, test_num_tmp[15] = {1,1,1,1,1,1,1,1,1,1,1,1};
    // int test_num[15][15][15];
    // for(int a = 1; a <= 11; a++){
    //     for(int b = 1; b <= 11; b++){
    //         for(int c = 1; c <= 11; c++){
    //             for(int k = -1; k <= 1; k++){
    //                 test_num[a][b][c] = k;
    //             }
    //         }
    //     }
    // }
    // for(int a = 1; a <= 11; a++){
    //     for(int b = 1; b <= 11; b++){
    //         for(int c = 1; c <= 11; c++){
    //             cout << test_num[a][b][c] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    while(!flag){
        flag = true;
        for(int cnt = 1; cnt <= m; cnt++)
        if(step[cnt][0] == 1 || step[cnt][0] == 0 || step[cnt][0] == -1) {
            test_num[step[cnt][1]] = step[cnt][0];
        } else {
            if(step[cnt][0] == MAXN_PROMOT) {
                test_num[step[cnt][1]] = step[cnt][2];
            } else {
                test_num[step[cnt][1]] = opp(step[cnt][2]);
            }
        }
        for(int i = 1; i <= n; i++){
            if(test_num[i] != test_num_tmp[i]){
                flag = false;
                for(int j = 1; j <= n; j++){
                    test_num_tmp[j] = test_num[i];
                }
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(test_num[i] == 0) ans++;
    }
    cout << ans << endl;
}

void mode_2(){
    int n, m, ans = 0;
    int step[MAXN][3];
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        char promot;
        scanf("%c", &promot);
        
        int promot_num = promot_check(promot);
        if(promot_num == 1 || promot_num == 0 || promot_num == -1) {
            step[i][0] = promot_num;
            scanf("%d", &step[i][1]);
        }
    }
    //cin

    bool flag[MAXN];
    memset(flag, false, MAXN - 1);
    for(int i = m; i >= 1; i--){
        if(!flag[step[i][1]]) {
            flag[step[i][1]] = true;
            if(step[i][0] == 0) ans++;
        }
    }
    cout << ans << endl;
}

void mode_3(){
    int n, m;
    int step[MAXN][3];
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        char promot;
        scanf(" %c", &promot);
        
        int promot_num = promot_check(promot);
        //cout << promot_num << endl;
        if(promot_num == 0) {
            step[i][0] = promot_num;
            scanf("%d", &step[i][1]);
        }
        if(promot_num == MAXN_PROMOT) {
            step[i][0] = promot_num;
            scanf("%d%d", &step[i][1], &step[i][2]);
        }
    }
    //cin

    int ans = 0;
    bool flag[MAXN];
    memset(flag, false, MAXN - 1);
    for(int i = m; i >= 1; i--){
        if(step[i][0] == 0) {
            if(!flag[step[i][1]]) {
                flag[step[i][1]] = true;
                ans++;
            }
        } else {
            if(flag[step[i][2]]) {
                flag[step[i][1]] = true;
                ans++;
            }
            if(!flag[step[i][2]] && flag[step[i][1]]) {
                flag[step[i][1]] = false;
                ans--;
            }
        }
    }
    cout << ans << endl;
}

void mode_4(){

}

void mode_5(){

}
int main() {
    freopen("tribool.in", "r", stdin);//remember to change
    freopen("tribool.out", "w", stdout);
    
    cin >> c >> t;
    if(c == 1 || c == 2){
        for(int i = 1; i <= t; i++) mode_1();
    }
    if(c == 3 || c == 4){
        for(int i = 1; i <= t; i++) mode_2();
    }
    if(c == 5 || c == 6){
        for(int i = 1; i <= t; i++) mode_3();
    }
    if(c == 7 || c == 8){
        for(int i = 1; i <= t; i++) mode_4();
    }
    if(c == 9 || c == 10){
        for(int i = 1; i <= t; i++) mode_5();
    }

    return 0;
}