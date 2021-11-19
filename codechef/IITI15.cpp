#include<bits/stdc++.h>
#define lb lower_bound
#define endl "\n"
using namespace std;

const int mxn=2e4+7;
const int B=150;
int n, q, a[mxn], t[mxn], ans[mxn], sum;
struct query {
	int l, r, id;
} qr[mxn];

void upd (int u, int val) {
	while (u<=n) {
		t[u]+=val;
		u+=(u&-u);
	}
}
int get(int u) {
	int res=0;
	while (u>0) {
		res+=t[u];
		u-=(u&-u);
	}
	return res;
}
void compr() {
	vector<int> v;
	v.assign(a+1,a+n+1);
	sort(v.begin(),v.end());
	for (int i=1;i<=n;i++) a[i]=lb(v.begin(),v.end(),a[i])-v.begin()+1;
}
bool ss(query x, query y) {
	return x.l/B < y.l/B || (x.l/B == y.l/B && x.r < y.r);
}
void add(int u, int val, int type) {
	int res;
	if (type==0) res=get(u-1);
	else res=get(n) - get(u);
	upd(u,val);
	sum+=val*res;
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	compr();
	cin>>q;
	for (int i=1;i<=q;i++) {
		cin>> qr[i].l >> qr[i].r ;
		qr[i].id = i;
	}
	sort (qr+1,qr+q+1,ss);
	int l=1,r=0;
	for (int i=1;i<=q;i++) {
		while (l<qr[i].l) add(a[l++], -1, 0);
		while (l>qr[i].l) add(a[--l], 1, 0);
		while (r<qr[i].r) add(a[++r], 1, 1);
		while (r>qr[i].r) add(a[r--], -1, 1);
		ans[qr[i].id]=sum;
	}
	for (int i=1;i<=q;i++) cout<<ans[i]<<endl;
    return 0;
}


