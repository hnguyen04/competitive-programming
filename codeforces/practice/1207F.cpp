#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

const int mxn=5e5+7;
const int blk=707;
int a[mxn], rm[blk][blk], t, num,x,y;
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
	while (t--) {
		cin>>num>>x>>y;
		if (num==1) {
			a[x]+=y;
			for (int i=1;i<blk;i++) rm[x%i][i]+=y;
		}
		else {
			if (x<blk) cout<<rm[y][x]<<endl;
			else {
				int ans=0;
				for (int i=y;i<mxn;i+=x) ans+=a[i];
				cout<<ans<<endl;
			}
		}
	}
    return 0;
}


