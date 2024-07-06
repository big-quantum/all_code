#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 7;
int N, M;
int a[MAXN];

#define lfc (x << 1)
#define rgc ((x << 1) | 1)
#define mid ((l + r) >> 1)

int val[MAXN * 4], minVal[MAXN * 4], maxVal[MAXN * 4];
int tag[MAXN * 4];

void build(int x, int l, int r) {
	if(l == r) {
		val[x] = minVal[x] = maxVal[x] = a[l];
		return;
	}
	build(lfc, l, mid); build(rgc, mid + 1, r);
	val[x] = val[lfc] + val[rgc];
	minVal[x] = min(minVal[lfc], minVal[rgc]);
	maxVal[x] = max(maxVal[lfc], maxVal[rgc]);
}

int req;

void down(int x, int l, int r) {
	tag[lfc] += tag[x], tag[rgc] += tag[x];
	val[lfc] += tag[x] * (mid - l + 1);
	val[rgc] += tag[x] * (r - mid);
	minVal[lfc] += tag[x], minVal[rgc] += tag[x];
	maxVal[lfc] += tag[x], maxVal[rgc] += tag[x];
	tag[x] = 0;
}

void modify(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		val[x] += (r - l + 1) * req;
		minVal[x] += req, maxVal[x] += req;
		tag[x] += req;
		return;
	}
	if(r < L || R < l) return;
	if(tag[x]) down(x, l, r);
	modify(lfc, l, mid, L, R); modify(rgc, mid + 1, r, L, R);
	val[x] = val[lfc] + val[rgc];
	valMin[x] = min(valMin[lfc], valMin[rgc]);
	valMax[x] = max(valMax[lfc], valMax[rgc]);
}

int queryS(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) return val[x];
	if(r < L || R < l) return 0;
	if(tag[x]) down(x, l, r);
	return queryS(lfc, l, mid, L, R) + queryS(rgc, mid + 1, r, L, R);
}

//-10^9 ~ 10^9

int queryMin(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) return valMin[x];
	if(r < L || R < l) return 0x3f3f3f3f;
	if(tag[x]) down(x, l, r);
	return min(queryMin(lfc, l, mid, L, R), queryMin(rgc, mid + 1, r, L, R));
}

int queryMax(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) return valMax[x];
	if(r < L || R < l) return -0x3f3f3f3f;
	if(tag[x]) down(x, l, r);
	return max(queryMax(lfc, l, mid, L, R), queryMax(rgc, mid + 1, r, L, R));
}

#undef lfc
#undef rgc
#undef mid

int main() {
	
}
