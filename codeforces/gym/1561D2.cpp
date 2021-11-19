#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define ld  long double
#define st first
#define nd second
#define ar array
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
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
const int mxn=4e6+7;
int n, m, dp[mxn], sum[mxn];
signed main() {
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	dp[n]=sum[n]=1;
	for (int i=n-1;i>=1;i--) {
		dp[i]=sum[i+1];
		for (int j=2*i;j<=n;j+=i) {
			int r=min(n,j+(j/i)-1);
			dp[i]=(dp[i]+sum[j]-sum[r+1]+m*m)%m;
		}
		sum[i]=(sum[i+1]+dp[i])%m;
	}
	cout<<dp[1];
    return 0;
}


