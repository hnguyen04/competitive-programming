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
    	if (b%2) res=(res*a)%mod;
		a=(a*a)%mod;
    	b/=2;
    }
    return res%mod;
}
const int mxn=2e6+7;
int sieve[mxn], q, ft[mxn];
void era() {
	for (int i=2;i<mxn;i++) {
		if (!sieve[i]) {
			for (int j=i*i;j<mxn;j+=i) sieve[j]=i;
			sieve[i]=i;
		}
	}
}
void gt(int n) {
	ft[0]=1;
	for (int i=1;i<=n;i++) ft[i]=(ft[i-1]*i)%mod;
}
int divm(int a, int b) {
	int res=a%mod;
	res=(res*pw(b,mod-2))%mod;
	return res;
}
int C(int a, int b) {
	if (a<b) return 0;
	return divm(ft[a], (ft[b]*ft[a-b])%mod);
}
signed main() {
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    era();gt(2000001);
	cin>>q;
//	cout<<comb[10][3];
	while (q--) {
		int ans=1;
		int x,y;cin>>x>>y;
		while (x>1) {
			int t=sieve[x], cnt=0;
			while (x%t==0) {
				x/=t;
				cnt++;
			}
			ans=(ans*C(cnt+y-1,y-1))%mod;
		}
		ans=(ans*pw(2, y-1))%mod;
		cout<<ans<<endl;
	}
    return 0;
}





