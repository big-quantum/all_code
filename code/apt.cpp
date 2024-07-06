#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,score;
int main(){
	cin >> a >> b >> c >> d;
	if (a >= 90) score++;
	if (b >= 90) score++;
	if (c >= 90) score++;
	if (d >= 90) score++;
	if (score == 4) score++;
	if (a < 60 || b  < 60 || c < 60 || d < 60) 
		cout << "Poor LanYangYang" << endl;
	else 
		cout << score << endl;
	return 0;	

}
