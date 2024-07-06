#include<bits/stdc++.h>
using namespace std;

int n, a[1005], ans[1005];
string s;

string sss(string s){
    string ss = "#";
    for(auto a : s){
        ss += a + "#";
    }
    ss += "#";
    return s;
}

int main(){
    cin >> s;
    string ns = sss(s);
    int end; 
    for(int i = 1; i < ns.size(); i++){
        int left = i, right = i, step = 0, start = i;
        while(left >= 0 && right < ns.size() && ns[left] == ns[right]){
            left--;
            right++;
            step++;
            start = left;
        }
        
    }
    cout << s.substr(start, right - start + 1);
    return 0;
}
// int main() {
//     string s;
//     cin >> s;
//     string ns = "#";
//     for (auto c: s) {
//         ns.append(1, c);
//         ns.append("#");
//     }
//     int realStart = -1, maxL = -1;

//     // 回文子串的查找
//     for (int i = 0; i < ns.size(); i++) {
//         int left = i, right = i;
//         int start = i, step = 0;

//         // 左右扩展
//         while (left >= 0 && right < ns.size() && ns[left] == ns[right]) {
//             step++;
//             start = left;
//             left--;
//             right++;
//         }

//         // 更新子串长度，起点
//         if (maxL < step - 1) {
//             maxL = step - 1;
//             realStart = start; // 字符串是扩展之后的
//         }
//     }

//     int start = (realStart + 1) / 2 - maxL / 2;

//     if (start < 0) {
//         start = 0;
//     }
//     if (start + maxL > s.size()) {
//         maxL = s.size() - start;
//     }

//     cout << maxL << endl;
//     cout << s.substr(start, maxL) << endl;

//     return 0;
// }