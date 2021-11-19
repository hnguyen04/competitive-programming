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
int n;
map<vector<int>, char> mp;
void init() {
	mp[{1,0,0,1,0}]='a';
	mp[{1,1,0,2,0}]='b';
	mp[{2,0,0,1,1}]='c';
	mp[{2,1,0,1,2}]='d';
	mp[{1,1,0,1,1}]='e';
	mp[{2,1,0,2,1}]='f';
	mp[{2,2,0,2,2}]='g';
	mp[{1,2,0,2,1}]='h';
	mp[{1,2,0,1,2}]='j';
	mp[{1,0,1,2,0}]='k';
	mp[{1,1,1,3,0}]='l';
	mp[{2,0,1,2,1}]='m';
	mp[{2,1,1,2,2}]='n';
	mp[{1,1,1,2,1}]='o';
	mp[{2,1,1,3,1}]='p';
	mp[{2,2,1,3,2}]='q';
	mp[{1,2,1,3,1}]='r';
	mp[{1,2,1,2,2}]='t';
	mp[{1,0,2,2,1}]='u';
	mp[{1,1,2,3,1}]='v';
	mp[{1,2,1,1,3}]='w';
	mp[{2,0,2,2,2}]='x';
	mp[{2,1,2,2,3}]='y';
	mp[{1,1,2,2,2}]='z';
} 
signed main() {
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	init();
	cin>>n;
	while (n--) {
		vector<int> v;
		for (int i=1;i<=5;i++) {
			int u;
			cin>>u;v.pb(u);
		}
		cout<<mp[v];
	}
    return 0;
}





