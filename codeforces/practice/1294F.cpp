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
const int mxn=2e5+7;
int n, par[mxn], d[mxn];
vector<int> g[mxn],dia;
pa dfs(int u, int p, int dis) {
	par[u]=p;
	pa res={dis,u};
	for (auto i:g[u]) {
		if (i==p) continue;
		res=max(res, dfs(i,u,dis+1));
	}
	return res;
}
void bfs() {
	fill(d+1,d+n+1,-1);
	queue<int> q;
	for (auto i:dia) d[i]=0,q.push(i);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (auto i:g[u]) {
			if (d[i]!=-1) continue;
			d[i]=d[u]+1;
			q.push(i);
		}
	}
}
signed main() {
//	freopen("FILENAME.inp","r",stdin);
//	freopen("FILENAME.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<n;i++) {
		int u,v; cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	pa l=dfs(1,0,0);
	pa r=dfs(l.nd,0,0);
	int t=r.nd;
	while (t!=par[l.nd]) {
		dia.pb(t);
		t=par[t];
	}
	if(r.st == n-1){
        cout << n-1 << endl <<dia[0] << " " << dia[1] << " " <<dia.back();
        return 0;
    }
    bfs();
    pa ans={0,0};
    for (int i=1;i<=n;i++) ans=max(ans,{d[i],i});
    cout<<ans.st+r.st<<endl;
    cout<<l.nd<<" "<<r.nd<<" "<<ans.nd;
    return 0;
}


