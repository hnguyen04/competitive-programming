#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define endl "\n"
using namespace std;

const int mxn=1e5+7;
const int B=300;
int n, m, q, a[mxn],  cnt, sz[mxn], sum[mxn], hold[mxn];
bool exist[B][mxn];
long same[mxn][B];
vector<int> S[mxn], heavy;

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) {
        cin>>sz[i];
        for (int j=1, u;j<=sz[i];j++) cin>>u, S[i].pb(u);
        if (sz[i]>B) {
            heavy.pb(i);
            for (auto j:S[i]) sum[i]+=a[j], exist[cnt][j]=1;
            cnt++;
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=0;j<heavy.size();j++) {
            if (i==heavy[j]) continue;
            for (auto k:S[i]) same[i][j]+=exist[j][k]; 
        }
    }
    while (q--) {
        char x;
        int u;
        cin>>x>>u;
        if (x== '?') {
            int ans=0;
            if (sz[u]<=B) {
                for (auto i:S[u]) ans+=a[i];
                for (int i=0;i<cnt;i++) ans+=same[u][i]*hold[heavy[i]]; 
            }
            else {
                ans=sum[u]+hold[u]*S[u].size();
                for (int i=0;i<cnt;i++) ans+=same[u][i]*hold[heavy[i]]; 
            }
            cout<<ans<<endl;
        }
        else {
            int val; cin>>val;
            if (sz[u]>B) hold[u]+=val;
            else {
                for (auto i: S[u]) a[i]+=val;
                for (int i=0;i<cnt;i++) sum[heavy[i]]+=same[u][i]*val;
            }
        }
    }
    return 0;
}

