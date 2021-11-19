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
const int mxn=6e5+7;
int sum[mxn], pos[mxn], n, pre, ans;
void upd (int u, int val, int *t) {
	while (u<mxn) {
		t[u]+=val;
		u+=(u&-u);
	}
}
int get(int u, int *t) {
	int res=0;
	while (u>0) {
		res+=t[u];
		u-=(u&-u);
	}
	return res;
}
signed main() {
//	freopen("FILENAME.inp","r",stdin);
//	freopen("FILENAME.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) {
		int u; cin>>u;
		ans+=pre+u*(i-1);
		ans-=get(u,sum);
		pre+=u;
		for (int j=u;j+u<mxn;j+=u) {
			ans-=(get(j+u-1,pos)-get(j-1,pos))*j;
			upd(j,u,sum);
		}
		upd(u,1,pos);
		cout<<ans<<" ";
	}
    return 0;
}


