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
int b[7]={0,1,6,4,3,5,2};
int a[7],n,ans;
signed main() {
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    int k=6;
    while (n) {
    	a[k]=n%2;
    	k--;n/=2;
	}
	for (int i=1;i<=6;i++) {
		//cout<<a[i]<<" ";
		if (a[i]) swap(a[i], a[b[i]]);
	}
	int t=1;
	for (int i=6;i>0;i--) {
		ans+=a[i]*t;
		t*=2;
	}
	cout<<ans;
    return 0;
}





