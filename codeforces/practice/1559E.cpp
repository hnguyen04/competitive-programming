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
const int mod=998244353;
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
const int N=55;
int n, m, l[N], r[N], ans[mxn], dp[N][mxn];
int f(int x) {
	int M=m/x;
	for (int i=0;i<=n;i++) for (int j=0;j<=M;j++) dp[i][j]=0;
	dp[0][0]=1;
	for (int i=1;i<=n;i++) {
		int u=l[i]/x+(l[i]%x!=0), v=r[i]/x;
		if (u>v) return 0;
		for (int j=0;j<=M;j++) {
			int L=u+j, R=min(v+j,M);
			if (L>R) continue;
			dp[i][L]=(dp[i][L]+dp[i-1][j])%mod;
			dp[i][R+1]=(dp[i][R+1]+mod-dp[i-1][j])%mod;
		}
		for (int j=1;j<=M;j++) dp[i][j]=(dp[i][j-1]+dp[i][j])%mod;
	}
	int sum=0;
	for (int i=0;i<=M;i++) sum=(sum+dp[n][i])%mod;
	return sum;
}
signed main() {
//	freopen("FILENAME.inp","r",stdin);
//	freopen("FILENAME.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>l[i]>>r[i];
	for (int i=m;i>=1;i--) {
		ans[i]=f(i);
		for (int j=2*i;j<=m;j+=i) ans[i]=(ans[i]+mod-ans[j])%mod;
	}
	cout<<ans[1];
    return 0;
}
// so ans[i] la cach de day co gcd chia het cho i -> mobius -> ans[1]
//dp[i][j] la so day co tong = j khi xet den doan i
//-> voi moi gia tri j , co the update tu dp(i,j+l[i]) va dp(i,j+r[i]) len dp[i-1][j] -> prefix


