#include<bits/stdc++.h>
using namespace std;
struct node{
	int sx,sy,ex,ey;
}num[10005];
int n,a,b,g,k,x,y,ans = -1;
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a >> b >> g >> k;
		num[i].sx = a;
		num[i].sy = b;
		num[i].ex = a + g;
		num[i].ey = b + k;
	}
	cin >> x >> y;
	for(int i = n;i >= 1;i--)
		if (num[i].sx <= x && x <= num[i].ex && num[i].sy <= y && y <= num[i].ey){
			ans = i;
			break;
		}
	cout << ans << endl;
	return 0;
}
