#include<bits/stdc++.h>
using namespace std;
char number[30] = {'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'};
int main(){
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int num1 = 0, num2 = 0, cnt = 0;
        string s1, s2;
        while(s[cnt] >= 'A' && s[cnt] <= 'Z'){
            s1 += s[cnt++];
        }
        while(s[cnt] >= '0' && s[cnt] <= '9'){
            num1 *= 10;
            num1 += s[cnt++] - '0';
        }
        if(cnt == s.size()) {
            cnt = 0;
            while(s1[cnt] >= 'A' && s1[cnt] <= 'Z'){
                num2 *= 26;
                num2 += s[cnt++] - 'A' + 1;
            }
            cout << "R" << num1 << "C" << num2 << endl;
        } else {
            cnt++;
            while(s[cnt] >= '0' && s[cnt] <= '9'){
                num2 *= 10;
                num2 += s[cnt++] - '0';
            }
            while(num2){
                s2.push_back(number[num2 % 26]);
                num2 = num2 / 26 - !(num2 % 26);
            }
            for(int i = s2.size() - 1; i >= 0; i--){
                cout << s2[i];
            }
            cout << num1 << endl;
        }
    }
    return 0;
}