#include<bits/stdc++.h>
using namespace std;
const int mxn=707;
int dp[mxn][mxn][2],n,a[mxn], gg[mxn][mxn];
//dp l,r, side: possible if rooted at l-1 or r+1 
int sol(int l, int r, int side) {
	if (l>r) return 1;
	if (dp[l][r][side]!=-1) return dp[l][r][side];
	int val=(side==0 ? l-1 : r+1);
	for (int i=l;i<=r;i++) {
		if (gg[i][val]==1) continue;
		if (sol(l,i-1,1)&&sol(i+1,r,0)) return dp[l][r][side]=1;
	}
	return dp[l][r][side]=0;
}
signed main() {
//	freopen("FILENAME.inp","r",stdin);
//	freopen("FILENAME.out","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=0;i<=n;i++) for (int j=0;j<=n;j++) gg[i][j]=__gcd(a[i],a[j]),dp[i][j][0]=dp[i][j][1]=-1;
	for (int i=1;i<=n;i++) {
		if (sol(1,i-1,1)&&sol(i+1,n,0)) {
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
    return 0;
}


