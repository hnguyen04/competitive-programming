//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
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
//#define matrix vector<vector<int> >
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod=1000000007;
const ld E=1e-10;
const ld PI=acos(-1);
typedef pair<int,int> pa;
typedef pair<ld,ld> pd;
typedef priority_queue<int, vector<int> ,gr<int> > pi;
typedef priority_queue<pa, vector<pa> ,gr<pa> > pp;
int pw(int a,int b){
    int res=1;
    while(b){
    	if (b%2) res*=a;
		a*=a;
    	b/=2;
    }
    return res;
}
const int mxn=3e5+7;
int q, a[mxn],par[mxn][30], cost[mxn];
int f(int u) {
	for (int i=29;i>=0;i--) {
		if (a[par[u][i]]) u=par[u][i];
	}
	return u;
}
signed main() {
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
   // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>q>>a[0]>>cost[0];
	for (int i=1;i<=q;i++) {
		int t;cin>>t;
		if (t==1) {
			int p;cin>>p;
			cin>>a[i]>>cost[i];
			par[i][0]=p;
			for (int j=1;j<30;j++) par[i][j]=par[par[i][j-1]][j-1];
		}
		else {
			int v,w,cnt=0,prc=0;
			cin>>v>>w;
			while (w>0&&a[v]>0)  {
				int u=f(v);
				if (a[u]>=w) {
					prc+=w*cost[u];cnt+=w;
					a[u]-=w;
					w=0;
				}
				else {
					w-=a[u];
					cnt+=a[u];prc+=a[u]*cost[u];
					a[u]=0;
				}
			}
			cout<<cnt<<" "<<prc<<endl;fflush(stdout);
		}
	}
    return 0;
}



		

