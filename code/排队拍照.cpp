#include<bits/stdc++.h>
using namespace std;
int n,i;
long long t[50005],ans,s;
int main() {
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%lld",&t[i]);
	sort(t + 1,t + 1 + n);
	for(int i = 2; i <= n; i++) {
		s = s + t[i - 1];//t[1] + t[2] + ... + t[i - 1]
		ans += s;
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
