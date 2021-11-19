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
const int mxn=2e3+7;
const int M=1e6+7;
int n, m, mx[M],ans=1e9;
pa a[mxn],b[mxn];
signed main() {
//	freopen("FILENAME.inp","r",stdin);
//	freopen("FILENAME.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i].st>>a[i].nd;
	for (int i=1;i<=m;i++) cin>>b[i].st>>b[i].nd;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			int val=b[j].st-a[i].st;
			if (val<0) continue;
			mx[val]=max(mx[val],b[j].nd-a[i].nd+1);
		}
	}
	for (int i=1000000;i>=0;i--) {
		mx[i]=max(mx[i+1],mx[i]);
		ans=min(ans,i+mx[i]);
	}
	cout<<ans;
	
    return 0;
}


