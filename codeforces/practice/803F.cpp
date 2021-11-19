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
const int mxn=1e6+7;
int n, f[mxn], pw2[mxn], cnt[mxn];
vector<int> v;
signed main() {
//	freopen("FILENAME.inp","r",stdin);
//	freopen("FILENAME.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) {
		int val; cin>> val;
		cnt[val]++;
	}
	pw2[0]=1;
	for (int i=1;i<mxn;i++) pw2[i]=(pw2[i-1]*2)%mod;
	for (int i=1000000;i>=1;i--) {
		int ct=0;
		for (int j=i;j<mxn;j+=i) ct+=cnt[j];
		f[i]=(pw2[ct]-1+mod)%mod;
		for (int j=2*i;j<mxn;j+=i) f[i]=(f[i]-f[j]+mod)%mod;
	}
	cout<<f[1];
    return 0;
}


