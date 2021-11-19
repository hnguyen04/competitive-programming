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
const int mxn=5e5+7;
int n, a[mxn], pre[mxn],val;
signed main() {
//	freopen("FILENAME.inp","r",stdin);
//	freopen("FILENAME.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<=(n+1)/2;i++) cin>>a[i],pre[i]=pre[i-1]+a[i];
	cin>>val; 
	for (int i=(n+1)/2+1;i<=n;i++) pre[i]=pre[i-1]+val;
	if (pre[n]>0) return cout<<n, 0;
	if (val>=0) return cout<<-1, 0;
	int mx=-1e18;
	for (int i=0;i<=(n+1)/2;i++) {
		mx=max(mx, pre[i]+val*(n-i));
		if (pre[n]+val*(n-i)>mx) return cout<<n-i, 0;
	}
	cout<<-1;
    return 0;
}
//pre[n]> 0 -> true
//x>0 -> -1
//x<0 -> ton tai k>=n/2 vi 1-k, k+1 -n true -> 1-2k true
//pre[i+k]-pre[i]>0 -> pre[i]<-pre[i+k]=pre[n]-val*(n-i-k) do k>=n/2 nen i+k+1 -> n deu = k
//-> pre[i]+val*(n-i) <pre[n]+val*k

