#include<bits/stdc++.h>
using namespace std;

int n;
string mapp[10][10];
map<char, int> num;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int cnt;
        for(int j = 1; j <= n; j++){
            cin >> mapp[i][j];
            if(mapp[i][j].length() > 1) cnt++;
        }
        num[mapp[i][1]] = cnt;
    }

    for(int i = 1; i <= n; i++){
          
    }
    return 0;
}