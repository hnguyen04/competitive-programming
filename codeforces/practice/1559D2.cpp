//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
//#pragma GCC optimize ("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define ld  long double
#define st first
#define nd second
#define ar array
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define gr greater
//#define matrix vector<vector<int> >
//#define FILENAME
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod=1000000007;
const ld E=1e-10;
const ld PI=acos(-1);
typedef pair<int,int> pa;
typedef pair<ld,ld> pd;
int pw(int a,int b){
    int res=1;
    while(b){
    	if (b%2) res*=a;
		a*=a;
    	b/=2;
    }
    return res;
}
const int mxn=1e5+7;
int n, par[2][mxn], rnk[2][mxn], m1, m2;
vector<pa> ans;
vector<int> a,b;
void init() {
	for (int i=1;i<=n;i++) {
		par[0][i]=par[1][i]=i;
		rnk[0][i]=rnk[1][i]=1;
	}
}
int f(int u, int id) {
	while (u!=par[id][u]) u=par[id][u];
	return u;
}
void join(int u, int v, int id) {
	u=f(u,id);v=f(v,id);
	if (u==v) return;
	if (rnk[id][u]<rnk[id][v]) swap(u,v);
	rnk[id][u]+=rnk[id][v];
	par[id][v]=u;
}
signed main() {
//	freopen("FILENAME.inp","r",stdin);
//	freopen("FILENAME.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m1>>m2;
	init();
	for (int i=1;i<=m1;i++) {
		int u,v;cin>>u>>v;
		join(u,v,0);
	}
	for (int i=1;i<=m2;i++) {
		int u,v;cin>>u>>v;
		join(u,v,1);
	}
	for (int i=2;i<=n;i++) {
		int u1=f(i,0),u2=f(i,1),v1=f(1,0),v2=f(1,1);
		if (u1!=v1&&u2!=v2) {
			ans.pb({1,i});
			join(1,i,0);
			join(1,i,1);
		}
	}
	for (int i=2;i<=n;i++) {
		if (f(i,0)!=f(1,0)&&f(i,0)==i&&f(i,1)==f(1,1)) a.pb(i);
		if (f(i,1)!=f(1,1)&&f(i,1)==i&&f(i,0)==f(1,0)) b.pb(i);
	}
	int sz=min(a.size(),b.size());
	for (int i=0;i<sz;i++) ans.pb({a[i],b[i]});
	cout<<ans.size()<<endl;
	for (auto i:ans) cout<<i.st<<" "<<i.nd<<endl;
    return 0;
}


