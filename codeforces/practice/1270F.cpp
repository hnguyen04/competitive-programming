#include<bits/stdc++.h>
#define lb lower_bound
#define ub upper_bound
using namespace std;

const int mxn=2e5+7;
const int M=1e7;
int n, a[mxn], pre[mxn], cnt[11*M];
long long ans;
string s;
int ceill (int x, int y) {
	int t=x/y;
	if (y*t< x) return t+1;
	return t;
}
// r - (l-1) = k * (pre[r] - pre [l-1])
// -> r - k * pre[r] = l' - k * pre[l']
// k < sqrt(n) = B -> brute, ez
// k > B -> pre[r] - pre[l'] = (r-l)/k <= n/B = B
// -> 2 pointer count cac string co so luong so 1 tu 1-B. k > B nen (r-l)/i > B hay r > l + i * B
signed main() {
	cin>>s; n=s.size();
	for (int i=0;i<n;i++) a[i+1]=(s[i]-'0'), pre[i+1]=pre[i]+a[i+1];
	int B=sqrt(n);
	for (int k=1;k<=B;k++) {
		for (int i=0;i<=n;i++) {
			int val=i - k*pre[i] + 10*M;
			ans+=cnt[val]; cnt[val]++;
		}
		for (int i=0;i<=n;i++) cnt[i - k*pre[i] + 10*M]=0;
	}
	for (int i=1;i*B<=n;i++) {
		for (int l=0;l<n;l++) {
			if (pre[n]-pre[l]<i) continue;
			int R=ub(pre+l, pre+n+1, pre[l]+i) - pre - 1;
			int L=lb(pre+l, pre+n+1, pre[l]+i) - pre;
			L=max(L,l + i*B + 1);
			if (L<=R) ans+= (R-l)/i - ceill(L-l)/i + 1;
		}
	}
	cout<<ans;
	
}


