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
bool ck(string s){
	int cnt=0;
	for (auto i:s) {
		if (i=='(') cnt++;
		else cnt--;
		if (cnt<0) return false;
	}
	if (cnt==0) return true;
	return false;
}
signed main() {
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while (t--) {
		int n; string s;
		cin>>n>>s;
		string a="",b="";
		
		int cnt1=0, cnt2=0;
		if (s[0]=='0'||s[n-1]=='0'||n%2==1) {
			cout<<"NO"<<endl;
			continue;
		} 
		a+='(';b+='(';
		for (int i=1;i<n-1;i++) {
			char j=s[i];
			if (j=='1') {
				if (cnt1%2) {
					a+=')';b+=')';
				}
				else {
					a+='(';b+='(';
				}
				cnt1++;
			}
			else {
				if (cnt2%2) {
					a+=')';b+='(';
				}
				else {
					a+='(';b+=')';
				}
				cnt2++;
			}
		}
		a+=')';b+=')';
		if (ck(a)&&ck(b)) {
			cout<<"YES"<<endl;
			cout<<a<<endl<<b<<endl;
		}
		else cout<<"NO"<<endl;
	}
    return 0;
}





