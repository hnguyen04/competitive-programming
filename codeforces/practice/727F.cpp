#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define ub upper_bound
#define endl "\n"
using namespace std;
const int mxn=757;
int n, m, a[mxn], h;
vector<int> vals;
int get(int u) {
	priority_queue<int, vector<int>, greater<int> > pq; 
	int sum=u;
	for (int i=1;i<=n;i++) {
		pq.push(a[i]);
		sum+=a[i];
		if (sum<0) {
			sum-=pq.top();
			pq.pop();
		}
	}
	return n-pq.size();
}
int bin(int u) {
	if (get(0)==u) return 0;
	int l=0, r=1e12;
	while (l+1<r) {
		int mid=(l+r)/2;
		if (get(mid)>u) l=mid;
		else r=mid;
	}
	return r;
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	h=get(0);
	for (int i=h;i>=0;i--) vals.pb(bin(i));
	for (int i=1, x;i<=m;i++) {
		cin>>x;
		int l=ub(vals.begin(),vals.end(),x)-vals.begin()-1;
		cout<<h-l<<endl;
	}
    return 0;
}


