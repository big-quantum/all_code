#include<bits/stdc++.h>
using namespace std;
string s;

map<string, map<string, string>> mode = {
    {
        "cin", {
        {"sign", "+-"}, 
        {"dot", "point_without_int"}, 
        {"number", "int"}, 
        {"number", "float"}, 
        {"others", "stop"}
        }
    }, {"+-", {
        {"number", "int"}, 
        {"dot", "point_without_int"}, 
        {"others", "stop"}
        }
    }, {"int", {
        {"number", "int"}, 
        {"dot", "point_with_int"}, 
        {"e/E", "eE"}, {"space", "end"}, 
        {"others", "stop"}
        }
    }, {"point_without_int", {
        {"number", "float"}, 
        {"space", "end"}, 
        {"others", "stop"}
        }
    }, {"point_with_int", {
        {"number", "float"}, 
        {"e/E", "eE"}, 
        {"space", "end"}, 
        {"others", "stop"}
        }
    }, {"float", {
        {"number", "float"}, 
        {"e/E", "eE"}, 
        {"space", "end"}, 
        {"others", "stop"}
        }
    }, {"eE", {
        {"sign", "e_+-"}, 
        {"number", "e_num"}, 
        {"others", "stop"}
        }
    }, {"e_+-", {
        {"number", "e_num"}, 
        {"space", "end"}, 
        {"others", "stop"}
        }
    }, {"e_num", {
        {"number", "e_num"}, 
        {"space", "end"}, 
        {"others", "stop"}
        }
    }, {"end", {
        {"space", "end"}, 
        {"others", "stop"}
        }
    }
};
string check(char c){
    if(c == '+' || c == '-') return "sign";
    if(c >= '0' && c <= '9') return "number";
    if(c == '.') return "dot";
    if(c == ' ') return "space";
    if(c == 'e' || c == 'E') return "e/E";
    return "others";
}

int main(){
    cin >> s;
    if(s.length() == 0){
        cout << "false" << endl;
        return 0;
    }
    string stype = "cin";
    for(int i = 0; i <= s.length(); i++){
        string ctype = check(s[i]);
        if(mode[stype].find(ctype) == mode[stype].end()){
            cout << "false" << endl;
            return 0;
        } else {
            stype = mode[stype][ctype];
        }
    }
    cout << "true" << endl;
    return 0;
}