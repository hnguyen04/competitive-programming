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
const int mxn=2e7+7;
int t;
int seive[mxn];
void eura() {
	for (int i=2;i<mxn;i++) {
		if (!seive[i]) {
			for (int j=i;j<mxn;j+=i) seive[j]++;
		}
	}
}
int cnt(int c, int d, int n, int u) {
	if ((n/u+d)%c) return 0; 
	return 1<<seive[(n/u+d)/c];
}
signed main() {
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    eura();
  //  for (int i=1;i<=30;i++) cout<<seive[i]<<" ";
	cin>>t;
	while (t--) {
		int c,d,n,ans=0;
		cin>>c>>d>>n;
		for (int i=1;i<=sqrt(n);i++) {
			if (n%i==0) {
				ans+=cnt(c,d,n,i);
				if (i*i!=n) ans+=cnt(c,d,n,n/i);
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}





