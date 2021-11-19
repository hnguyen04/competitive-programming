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
    	if (b%2) res=(res*a)%mod;
		a=(a*a)%mod;
    	b/=2;
    }
    return res;
}
int n, k;
map<int,int> f;
int sol(int val) {
	if (f.count(val)) return f[val];
	int res=pw(2,val-1);
	int sq=sqrt(val);
	for (int i=2;i<=sq;i++) {
		if (val%i!=0) continue;
		res=(res-sol(i)+mod)%mod;
		if (i*i!=val) res=(res-sol(val/i)+mod)%mod;
	}
	res=(res-1+mod)%mod;
	return f[val]=res;
}
signed main() {
//	freopen("FILENAME.inp","r",stdin);
//	freopen("FILENAME.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	f[1]=1;
	if (k%n!=0) cout<<0;
	else cout<<sol(k/n);
    return 0;
}


