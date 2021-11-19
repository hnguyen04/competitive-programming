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
int n,m,ans=1e18;
vector<int> va,vb;
signed main() {
//	freopen("FILENAME.inp","r",stdin);
//	freopen("FILENAME.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i*i<=n;i++) if (n%i==0) va.pb(i);
	for (int i=1;i*i<=m;i++) if (m%i==0) vb.pb(i);
	int l1=0,l2=0;
	int a=va.size(),b=vb.size();
	for (int i=1;i*i<=m+n;i++) {
		if ((m+n)%i!=0) continue;
		int x=(m+n)/i;
		while (l1+1<a&&va[l1+1]<=i) l1++;
		while (l2+1<b&&vb[l2+1]<=i) l2++;
		if (min(n/va[l1],m/vb[l2])<=x) ans=min(ans,2*(i+x));
	}
	cout<<ans;
    return 0;
}


