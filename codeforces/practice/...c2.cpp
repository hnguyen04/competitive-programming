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
const int mxn=2e5+7;
int a[mxn], sum[mxn], n, ans, bn=0;
priority_queue<int> pq;

signed main() {
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];sum[i]=sum[i-1]+a[i];
	}
	for (int i=1;i<=n;i++) {
		if (a[i]<0) pq.push(abs(a[i]));
		while (sum[i]+bn<0) {
			int t=pq.top();
			pq.pop();
			bn+=t;
			ans++;
		}
	}
	cout<<n-ans;
    return 0;
}





