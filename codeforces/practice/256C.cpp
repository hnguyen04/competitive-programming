#include<bits/stdc++.h>
using namespace std;

const int mxn=5e3+7;
int n, a[mxn];
int solve (int l, int r, int h) {
	if (l > r) return 0;
	int t = min_element (a+l, a+r+1) - a;
	return min(solve (l, t-1, a[t]) + solve (t+1, r, a[t]) + a[t] - h, r-l+1);
}
signed main() {
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	cout << solve (1, n, 0);
    return 0;
}


