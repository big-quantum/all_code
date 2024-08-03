#include<bits/stdc++.h>
using namespace std;

int n, m, cnta, cntb;
string a, b;
int pos[200005];

int main(){
	cin >> n >> m;
	cin >> a >> b;
	for(int i = 0; i < a.size(); i++){
		if(a[i] == '#'){
			pos[cnta] = i;
			cnta++;
		}
	}
	int cnt = 0, cntt = 0, tmp = cnta;
	cntb = m - cnta;
	while(cnta > 0){
		if(cntb < 26){
			for(int i = cntt; i < tmp; i++){
				cnt++;
				if(cntb > 0 && cntb + cnt - 1 == 26){
					cntb = 0;
					cnt = 1;
					a[pos[i]] = char((cnt - 1) % 26 + 'a');
					cnta--;
					continue;
				}
				a[pos[i]] = char((cnt - 1) % 26 + 'a');
				cnta--;
			}
		} else {
			cntb -= 25;
			a[pos[cntt++]] = 'a';
			cnta--;
		}
	}
	cout << a << endl;
	return 0;
}
//
//ab##asdafha#ssfasjdjhkffdedalsk
//da########################dfewg
