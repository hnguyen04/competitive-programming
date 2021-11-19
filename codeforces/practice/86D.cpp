#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int mxn=2e5+7;
const int B=800;
int n, a[mxn], ans[mxn], cnt[5*mxn], q, sum;
struct query{
	int l, r, id;
} qr[mxn];
bool ss (query x, query y) {
	if (x.l / B != y.l / B) return x.l / B < y.l / B;
    return x.r < y.r;
}
void add(int val, int pos) {
	int tmp=cnt[a[pos]];
	sum-=(tmp!=0);
	tmp+=val;
	sum+=(tmp!=0);
	cnt[a[pos]]=tmp;
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	cin>>q;
	for (int i=0,x,y;i<q;i++) {
		cin>>x>>y;
		qr[i]={x-1,y-1,i};
	}
	sort (qr,qr+q,ss);
	int l=0, r=-1;
	for (int i=0;i<q;i++) {
		while (l<qr[i].l) add(-1, l++);
		while (l>qr[i].l) add(1, --l);
		while (r<qr[i].r) add(1, ++r);
		while (r>qr[i].r) add(-1,r--);
		ans[qr[i].id]=sum;
	}
	for (int i=0;i<q;i++) cout<<ans[i]<<endl;
    return 0;
}


