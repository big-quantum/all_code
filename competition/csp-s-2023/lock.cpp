#include<bits/stdc++.h>
using namespace std;

int n, f[10][6];

int ans;
string s[10];
map<string, int> val;
string number[10] = {"0","1","2","3","4","5","6","7","8","9"};

void one(){
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= 5; j++) {
            for (int k = 0; k < 10; k++) {
                string tmp = s[i];
                if(k != s[i][j - 1]) {
                    tmp.replace(j - 1, 1, number[k]);
                    val[tmp]++;
                }
            }
        }
    }    
}

void two(){
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j < 5; j++) {
            for (int k = 1; k < 10; k++) {
                string tmp = s[i];
                tmp.replace(j - 1, 1, number[(s[i][j - 1] + k - '0') % 10]);
                tmp.replace(j, 1, number[(s[i][j] + k - '0') % 10]);
                val[tmp]++;
            }
        }
    }    
}

int main(){
    
    
    cin >> n; 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 5; j++){
            char a;
            cin >> a;
            s[i] += a;
            f[i][j] = a - '0';
        }
    }

    one();
    two();

    for(auto i : val){
        if(i.second == n) ans++;
    }
    cout << ans << endl;
    return 0;
}