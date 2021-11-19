#pragma GCC optimize ("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod=1000000007;
const ld E=1e-10;
const ld PI=acos(-1);
const int oo=1e18;
typedef pair<int,int> pa;
typedef pair<ld,ld> pd;
typedef priority_queue<int> pi;
typedef priority_queue<pa> pp;
typedef priority_queue<int, vector<int> ,gr<int> > pim;
typedef priority_queue<pa, vector<pa> ,gr<pa> > ppm;
int pw(int a,int b){
    int res=1;
    while(b){
    	if (b&1) res*=a;
		a*=a;
    	b>>=1;
    }
    return res;
}
const int mxn=2e5+7;
int n, k, a[mxn];
bool ck(int u) {
	int dp[mxn]={0};
	for (int i=1;i<=n;i++) {
		if (a[i]>=u) dp[i] = dp[i-1]+1;
		else if (a[i]<u) dp[i]=dp[i-1]-1;
	}
	int mn=1e18;
	for (int i=k;i<=n;i++) {
		mn=min(mn, dp[i-k]);
		if (dp[i]-mn>0) return true;
	}
	return false;
}
signed main() {
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    int l=0, r=1e9;
    //ck(4);
	while (l+1<r) {
		int mid=(l+r)/2;
		if (ck(mid)) l=mid;
		else r=mid;
	}
	cout<<l;
    return 0;
}





