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
int n,q,k,vis[mxn],t,par[mxn], rnk[mxn], op[mxn];
string s[mxn];
map<string, int> mp;
int f(int u) {
	while (u!=par[u]) u=par[u];
	return u;
}
int en(int u) {
	u=f(u);
	if (op[u]==-1) return -1;
	return f(op[u]);
}
void join(int u, int v) {
	u=f(u);v=f(v);
	if (u==v) return ;
	if (rnk[u]<rnk[v]) rnk[v]+=rnk[u],par[u]=v;
	else rnk[u]+=rnk[v],par[v]=u;
}
int isfr(int u, int v) {
	u=f(u);v=f(v);
	int uu=en(u),vv=en(v);
	if (uu==v||vv==u) return 0;
	join(u,v);
	if (uu!=-1&&vv!=-1) join(uu,vv);
	if (uu!=-1) op[uu]=u;
	if (vv!=-1) op[vv]=u;
	op[u]=max(uu,vv);
	op[v]=max(uu,vv);
	return 1;
}
int isen(int u, int v) {
	u=f(u);v=f(v);
	int uu=en(u),vv=en(v);
	if (u==v||(uu==vv&&uu!=-1)) return 0;
	if (uu!=-1) join(v,uu);
	if (vv!=-1) join(u,vv);
	op[u]=v;
	op[v]=u;
	return 1;
}

signed main() {
//	freopen("FILENAME.inp","r",stdin);
//	freopen("FILENAME.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>q>>k;
	for (int i=1;i<=n;i++) {
		cin>>s[i];
		mp[s[i]]=i;
		par[i]=i;
		rnk[i]=1;
		op[i]=-1;
	}
	for (int i=1;i<=q;i++) {
		int num;cin>>num;
		string u,v;cin>>u>>v;
		int x=mp[u],y=mp[v];
		int ok=1;
		if (num==1) ok=isfr(x,y);
		else ok=isen(x,y);
		cout<<(ok==1 ? "YES" : "NO")<<endl;
	}
	for (int i=1;i<=k;i++) {
		int ans=3;
		string u,v;cin>>u>>v;
		int x=mp[u],y=mp[v];
		if (f(x)==f(y)) ans=1;
		if (f(x)==en(y)) ans=2;
		cout<<ans<<endl;
	}
    return 0;
}


