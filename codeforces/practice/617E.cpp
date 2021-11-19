#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int mxn=1e5+7;
const int B=350;
int n, a[mxn], ans[mxn], cnt[20*mxn], q, sum, pre[mxn], k;
struct query{
	int l, r, id;
} qr[mxn];
bool ss (query x, query y) {
	if (x.l / B != y.l / B) return x.l / B < y.l / B;
    return x.r < y.r;
}
void add(int pos) {
	sum+=cnt[pre[pos]^k];
	cnt[pre[pos]]++;
}
void sub(int pos) {
	cnt[pre[pos]]--;
	sum-=cnt[pre[pos]^k];
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>q>>k;
	for (int i=1;i<=n;i++) cin>>a[i], pre[i]=pre[i-1]^a[i];
	for (int i=1;i<=q;i++) cin>>qr[i].l>>qr[i].r, qr[i].id=i, qr[i].l--;
	sort (qr+1,qr+q+1,ss);
	int l=0, r=-1;
	for (int i=1;i<=q;i++) {
		while (l<qr[i].l) sub(l++);
		while (l>qr[i].l) add(--l);
		while (r<qr[i].r) add(++r);
		while (r>qr[i].r) sub(r--);
		ans[qr[i].id]=sum;
	}
	for (int i=1;i<=q;i++) cout<<ans[i]<<endl;
    return 0;
}


