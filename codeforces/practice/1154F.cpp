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
int a[mxn],n,m,k, sum[mxn],dp[mxn];
pa b[mxn];
signed main() {
//	freopen("FILENAME.inp","r",stdin);
//	freopen("FILENAME.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++) cin>>b[i].st>>b[i].nd;
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	fill(dp+1,dp+k+1,1e9);
	for (int i=1;i<=k;i++) {
		dp[i]=min(dp[i],dp[i-1]+a[i]);
		for (int j=1;j<=m;j++) {
			if (i<b[j].st) break;
			dp[i]=min(dp[i],dp[i-b[j].st] + sum[i] - sum[i-(b[j].st-b[j].nd)]);
		}
	}
	cout<<dp[k];
    return 0;
}


