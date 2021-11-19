#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int mod=1000000007;
typedef pair<int,int> pa;
int pw(int a,int b){
    int res=1;
    while(b){
    	if (b%2) res=(res*a)%mod;
		a=(a*a)%mod;
    	b/=2;
    }
    return res%mod;
}
const int mxn=2e5+7;
int n, q, a[mxn], d, seive[mxn];
multiset<int> s[mxn];
map<pa,int> mp;
void era() {
	for (int i=2;i<mxn;i++) {
		if (!seive[i]) {
			for (int j=i+i;j<mxn;j+=i) seive[j]=i;
			seive[i]=i;
		}
	}
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	era();
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	d=a[1];
	for (int i=1;i<=n;i++) d=__gcd(d, a[i]);
	for (int i=1;i<=n;i++) {
		int r=a[i];
		while (r>1) {
			int t=seive[r];
			mp[{i,t}]++;
			if (t!=seive[r/t]) s[t].insert(mp[{i,t}]);
			r/=t;
		}
	}
	while (q--) {
		int pos, val;
		cin>>pos>>val;
		while (val>1) {
			int t=seive[val],cnt=0;
			while (val%t==0) {
				val/=t;
				cnt++;
			}
			int l=mp[{pos,t}],od=0,nw=0;
			if (s[t].size()==n) od=*s[t].begin();
			mp[{pos,t}]+=cnt;
			if (l) {
				auto it=s[t].find(l);
				if(it!=s[t].end()) s[t].erase(it);
			}
			s[t].insert(l+cnt);
			if (s[t].size()==n) nw=*s[t].begin();
			d=(d*pw(t,nw-od))%mod;
		}
		cout<<d<<endl;
	}
    return 0;
}





