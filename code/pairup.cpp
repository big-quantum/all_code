#include<bits/stdc++.h>
using namespace std;
struct cow{
	int x,y;
}a[100005]; 
bool mycmp(cow A,cow B){
	return A.y < B.y;
}
int n,ans,lft,rgt;
int main(){
	freopen("pairup.in","r",stdin);
	freopen("pairup.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a + 1,a + 1 + n,mycmp);
	lft = 1;
	rgt = n;
	while(lft <= rgt){
		int tmp = min(a[lft].x,a[rgt].x);
		ans = max(ans,a[lft].y + a[rgt].y);
		a[lft].x -= tmp;
		if (a[lft].x == 0) lft++;
		a[rgt].x -= tmp;
		if (a[rgt].x <= 0) rgt--;
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
