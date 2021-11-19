#include<bits/stdc++.h>
#define st first
#define nd second
#define ar array
#define pb push_back
using namespace std;
typedef pair<int,int> pa;
const int mxn=1e5+7;
int n, ans=1e9, vis[mxn];
vector<int> g[mxn];
void bfs(int u) {
	queue<pa> q;
	q.push({u,0});
	g[u].pb(0);
	vector<int> vt;
	vis[u]=1;vt.pb(u);
	while (!q.empty()) {
		int t=q.front().st,v=q.front().nd;q.pop();
		if (t*2<mxn&&!vis[t*2]) {
			g[t*2].pb(v+1);
			vt.pb(t*2);vis[t*2]=1;
			q.push({t*2,v+1});
		}
		if (!vis[t/2]) {
			g[t/2].pb(v+1);
			vt.pb(t/2);vis[t/2]=1;
			q.push({t/2,v+1});
		}
	}
	for (auto i:vt) vis[i]=0;
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
	for (int i=1, u;i<=n;i++) cin>>u, bfs(u);
	for (int i=0;i<=1e5;i++) {
		if (g[i].size()<n) continue;
		int sum=0;
		for (auto j:g[i]) sum+=j;
		ans=min(ans, sum);
	}
	cout<<ans;
    return 0;
}


