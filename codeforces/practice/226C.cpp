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
#define matrix vector<vector<int> >
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
set<int> s;
int m,l,r,k,num=1;
matrix mul(matrix v1, matrix v2) {
	int a1=v1.size(),b1=v1[0].size(),a2=v2.size(),b2=v2[0].size();
//	if (b1!=a2) {
//		matrix res(1, vector<int> (1, -1));
//		return res;
//	}
	matrix res(a1, vector<int> (b2, 0));
	for (int i=0;i<a1;i++) {
		for (int j=0;j<b2;j++) {
			for (int k=0;k<a2;k++) res[i][j]+=v1[i][k]*v2[k][j],res[i][j]%=m;
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
int fib(int n) {
	if (n==1) return 1%m;
	matrix fibo={{0,1},{1,1}};
	fibo=pwm(fibo,n-1);
	return fibo[1][1];
}
signed main() {
	freopen("FILENAME.inp","r",stdin);
	freopen("FILENAME.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>m>>l>>r>>k;
	for (int i=1;i*i<=r;i++) {
		s.insert(i);
		s.insert(r/i);
	}
	for (int i=1;i*i<=l;i++) s.insert(l/i);
	for (auto i:s) if ((r/i)-(l/i+(l%i!=0))+1>=k) num=i;
	cout<<fib(num);
    return 0;
}


