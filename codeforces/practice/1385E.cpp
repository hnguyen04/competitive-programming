#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define endl "\n"
using namespace std;
typedef pair<int,int> pa;

const int mxn=2e5+7;
int n, pos[mxn], vis[mxn], ok, m, t;
vector<int> g[mxn], topo;
vector<pa> edge;
void dfs(int u)
{
    vis[u]=1;
    for(auto i:g[u]) {
        if(vis[i]==1) {
        	ok=0;
        	return;
		}
       	if (!vis[i]) dfs(i);
	}
	topo.pb(u);
    vis[u]=2;
}
void sol() {
	ok=1;
	edge.clear();topo.clear();
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		g[i].clear();
		vis[i]=0;pos[i]=0;
	}
	for (int i=1,u,v,num;i<=m;i++) {
		cin>>num>>u>>v;
		if (num==1) g[u].pb(v);
		edge.pb({u,v});
	}
	
	for (int i=1;i<=n;i++) if (!vis[i]) dfs(i);
	if (!ok) {
		cout<<"NO"<<endl;
		return ;
	}
	cout<<"YES"<<endl;
	reverse(topo.begin(),topo.end());
	for (int i=0;i<topo.size();i++) pos[topo[i]]=i;
	for (auto i:edge) {
		if (pos[i.st]>pos[i.nd]) cout<<i.nd<<" "<<i.st<<endl;
		else cout<<i.st<<" "<<i.nd<<endl;
	}
}
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while (t--) sol();
    return 0;
}


