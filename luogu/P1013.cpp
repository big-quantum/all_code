#include<bits/stdc++.h>
using namespace std;

int n;
string mapp[10][10];
map<char, int> num;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            cin >> mapp[i][j];
            if(mapp[i][j].length() > 1) cnt++;
        }
        num[mapp[i][1][0]] = cnt;
    }
    bool flag = false;
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= n; j++){
            int tmp = num[mapp[i][1][0]] + num[mapp[1][j][0]];
            int cnt;
            if(mapp[i][j].length() > 1) cnt =(n - 1) + num[mapp[i][j][1]];
            else cnt = num[mapp[i][j][0]];
            if(cnt != tmp) flag = true;
        }
    }
    if(!flag){
        for(int i = 2; i <= n; i++){
            cout << mapp[i][1][0] << "=" << num[mapp[i][1][0]] << " ";
        }
        cout << endl;
        cout << n - 1;
    } else {
        cout << "ERROR!" << endl;
    }
    return 0;
}