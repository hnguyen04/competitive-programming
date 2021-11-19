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
const int mxn=4e5+7;
int t, vis[mxn], ans[mxn], cyc[mxn], more[mxn],n,m;
vector<int> g[mxn];

void dfs(int u, int color) {
	vis[u]=1;
	ans[u]=color;
	for (auto i:g[u]) {
		if (vis[i]==0) dfs(i,color);
		else if (vis[i]==1) cyc[i]=1;
		else if (vis[i]==2) more[i]=1;
	}
	vis[u]=2;
}
void sol() {
	cin>>n>>m;
	while (m--) {
		int u,v;cin>>u>>v;
		g[u].pb(v);
	}
	dfs(1,1);
	fill(vis+1,vis+n+1,0);
	for (int i=1;i<=n;i++) if (cyc[i]) dfs(i,-1);
	for (int i=1;i<=n;i++) if (more[i]&&!vis[i]) dfs(i,2);
	for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<endl;
	fill(vis+1,vis+n+1,0);
	fill(ans+1,ans+n+1,0);
	fill(cyc+1,cyc+n+1,0);
	fill(more+1,more+n+1,0);
	for (int i=1;i<=n;i++) g[i].clear();
}
signed main() {
//	freopen("FILENAME.inp","r",stdin);
//	freopen("FILENAME.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while (t--) sol();
    return 0;
}


