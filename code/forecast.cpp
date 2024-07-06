#include<bits/stdc++.h>
using namespace std;
string s;

int main(){
	cin >> s;
	if (s == "Sunny")
		cout << "Cloudy" << endl;
	if (s == "Cloudy")
		cout << "Rainy" << endl;
	if (s == "Rainy")
		cout << "Sunny" << endl;
	return 0;
}
