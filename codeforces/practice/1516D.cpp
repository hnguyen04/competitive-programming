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
int n, a[mxn], q, dp[mxn][21], seive[mxn], nxt[mxn];
void era() {
	for (int i=2;i<mxn;i++) {
		if (seive[i]) continue;
		for (int j=i*i;j<mxn;j+=i) seive[j]=i;
		nxt[i]=n+1;
		seive[i]=i;
	}
}
signed main() {
//	freopen("FILENAME.inp","r",stdin);
//	freopen("FILENAME.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	era();
	for (int i=1;i<=n;i++) cin>>a[i];
	dp[n+1][0]=n+1;
	for (int i=n;i>=1;i--) {
		dp[i][0]=dp[i+1][0];
		int k=a[i];
		while (k>1) {
			int t=seive[k];
			dp[i][0]=min(nxt[t],dp[i][0]);
			nxt[t]=i;
			while (k%t==0) k/=t;
		}
	}
	for (int j=1;j<=20;j++) {
		for (int i=1;i<=n+1;i++) dp[i][j]=dp[dp[i][j-1]][j-1];
	}
	while (q--) {
		int l,r,ans=1;cin>>l>>r;
		for (int i=20;i>=0;i--) {
			if (dp[l][i]<=r) {
				l=dp[l][i];
				ans+=(1<<i);
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}


