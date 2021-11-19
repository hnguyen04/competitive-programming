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
#define matrix vector<vector<int> >
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod=4294967296;
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
//Na2S2O3 + 2HCl = S + SO2 + 2NaCl + H2O
int n, ans;
int dx[8]={1,1,2,2,-1,-1,-2,-2};
int dy[8]={2,-2,1,-1,2,-2,1,-1};
int mulmod(int x, int y) {
	int res=0;
	while (y) {
		if (y%2) res=(res+x)%mod;
		x=(x+x)%mod;
		y/=2;
	}
	return res;
}
matrix mul(matrix v1, matrix v2) {
	int a1=v1.size(),b1=v1[0].size(),a2=v2.size(),b2=v2[0].size();
	if (b1!=a2) {
		matrix res(1, vector<int> (1, -1));
		return res;
	}
	matrix res(a1, vector<int> (b2, 0));
	for (int i=0;i<a1;i++) {
		for (int j=0;j<b2;j++) {
			for (int k=0;k<a2;k++) res[i][j]=(res[i][j]+mulmod(v1[i][k],v2[k][j])%mod)%mod;
		}
	}
	return res;
}
matrix pwm(matrix a, int b) {
	if (a.size()!=a[0].size()) return {{-1}};
	if (b==1) return a;
	matrix res=pwm(a, b/2);
	res=mul(res,res);
	if (b%2) res=mul(res,a);
	return res;
}
void pmat (matrix m) {
	for (auto i:m) {
		for (auto j:i) cout<<j<<" ";
		cout<<endl;
	}
}
int hs(int x, int y) {
	if (x<0||y<0) return -1;
	if (x>7||y>7) return -1;
	return 8*x+y;
}
 signed main() {
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    matrix m(65, vector<int> (65,0)) ;
    matrix vec(65, vector<int> (65,0)) ;
    vec[0][0]=1;
    for (int i=0;i<8;i++) {
    	for (int j=0;j<8;j++) {
    		int p=hs(i,j);
    		for (int id=0;id<8;id++) {
    			int k=hs(i+dx[id],j+dy[id]);
    			if (k==-1) continue;
    			m[p][k]=1;
//    			if (id==9) continue;
			}
		}
	}
	for (int i=0;i<=64;i++) m[i][64]=1;
	m=pwm(m,n+1);
	vec=mul(vec,m);
	cout<<vec[0][64];
    return 0;
}

