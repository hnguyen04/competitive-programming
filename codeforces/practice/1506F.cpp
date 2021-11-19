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
int t;

int dis(pa a, pa b) {
	if (a.st-a.nd==b.st-b.nd) {
		if ((a.st+a.nd)%2==0) return b.st-a.st;
		else return 0;
	}
	b.st-=a.st-1;
	b.nd-=a.nd-1;
	int t=b.st-b.nd;
	if ((a.st+a.nd)%2) return (t+1)/2;
	else return t/2;
}
signed main() {
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while (t--) {
		int n, ans=0;
		cin>>n;
		vector<pa> v(n+1);
		v[0]={1,1};
		for (int i=1;i<=n;i++) cin>>v[i].st;
		for (int i=1;i<=n;i++) cin>>v[i].nd;
		sort(v.begin(), v.end());
		for (int i=0;i<n;i++) ans+=dis(v[i], v[i+1]);
		cout<<ans<<endl;
	}
    return 0;
}





