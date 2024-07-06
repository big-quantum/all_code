#include<bits/stdc++.h>
using namespace std;
#define Maxn 100
int n,stu[Maxn + 5],apple[Maxn + 5];
bool suc = true;

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> stu[i];
	for(int i = 1;i <= n;i++)
		cin >> apple[i];
	sort(stu + 1,stu + 1 + n);
	sort(apple + 1,apple + 1 + n);
	for(int i = 1;i <= n;i++)
		if (apple[i] < stu[i]){
			suc = false;	
			break;
		}
	if (suc) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;	
}


