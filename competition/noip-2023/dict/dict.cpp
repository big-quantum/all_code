#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

string dict[3005], dict_min;

int n, m;
int abc[30][3005];

void cnt_abc(string s, int number){
    for (int i = 0; i < m; i++) {
        abc[s[i] - 'a'][number]++;
    }
}

int main() {
    freopen("dict.in", "r", stdin);//remember to change
    freopen("dict.out", "w", stdout);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> dict[i];
        cnt_abc(dict[i], i);
    }
    
    sort(dict + 1, dict + n + 1);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 26; j++){
            dict_min.append(abc[j][i], char(j + 'a'));
        }
        //cout << dict_min << endl;
        if(dict_min <= dict[1] ||(dict_min == dict[1] && m == 1)) cout << 1;
        else cout << 0;
        dict_min = "";
    }
    cout << endl;
    return 0;
}