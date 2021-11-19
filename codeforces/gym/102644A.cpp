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
#define matrix vector<vector<ld> >
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
    	if (b%2) res*=a;
		a*=a;
    	b/=2;
    }
    return res;
}
matrix mul(matrix v1, matrix v2) {
	int a1=v1.size(),b1=v1[0].size(),a2=v2.size(),b2=v2[0].size();
	int r,c;
	if (b1!=a2) {
		matrix res(1, vector<ld> (1, -1));
		return res;
	}
	matrix res(a1, vector<ld> (b2, 0));
	for (int i=0;i<a1;i++) {
		for (int j=0;j<b2;j++) {
			for (int k=0;k<a2;k++) res[i][j]=res[i][j]+v1[i][k]*v2[k][j];
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
int n;
ld p;
signed main() {
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
    cin>>n>>p;
    matrix m1={{1,0}};
    matrix m2={{1-p,p},{p,1-p}};
	m2=pwm(m2,n);
	m1=mul(m1,m2);
	cout<<fixed<<setprecision(10)<<m1[0][0];
}
