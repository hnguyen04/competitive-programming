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
const int mxn=5e5+7;
int a,b,k, x[mxn], y[mxn];
signed main() {
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>a>>b>>k;
	if ((a<1||b<2||a+b-k<2)&&k>0) {
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	if (k==0) {
		fill(x+1, x+b+1,1);
		fill(y+1, y+b+1,1);
		for (int i=1;i<=a+b;i++) cout<<x[i];
		cout<<endl;
		for (int i=1;i<=a+b;i++) cout<<y[i];
		return 0;
	}
	if (a>k) {
		fill(x+1, x+b,1);
		fill(y+1,y+b,1);
		x[a+b-k]=1;y[a+b]=1;
	}
	else {
		fill (x+1, x+b+1, 1);
		fill(y+1, y+b+1, 1);
		swap(y[a+b], y[a+b-k]);
	}
	for (int i=1;i<=a+b;i++) cout<<x[i];
	cout<<endl;
	for (int i=1;i<=a+b;i++) cout<<y[i];
    return 0;
}





