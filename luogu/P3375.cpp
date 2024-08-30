#include<bits/stdc++.h>
using namespace std;

string s1, s2;
int ne[1000005];
vector<int> pos;

int main(){
    cin >> s1 >> s2;
    int m = s2.size(), n = s1.size();
    s1 = "1" + s1;
    s2 = "1" + s2;
    ne[1] = 0;
    for(int i = 2, j = 0; i <= m; i++){
        while(j > 0 && s2[i] != s2[j + 1]) j = ne[j];
        if(s2[i] == s2[j + 1]) j++;
        ne[i] = j;
    }
    for(int i = 1, j = 0; i <= n; i++){
        while(j > 0 && s1[i] != s2[j + 1]) j = ne[j];
        if(s1[i] == s2[j + 1]) j++;
        if(j == m) pos.push_back(i - j + 1);
    }

    for(auto i : pos){
        cout << i << endl;
    }
    for(int i = 1; i <= m; i++){
        cout << ne[i] << " ";
    }
    return 0;
}