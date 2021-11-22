#include<bits/stdc++.h>
#define int long long
#define lll __int128
using namespace std;
const int mxn=2e5+7;
int n, k, a[mxn];
bool check(int u) {
    lll sum=0, coef=1;
    for (int i=1;i<=n;i++) {
        sum+=coef*a[i];
        if (sum>=k) break;
        if (coef>=1e18) continue;
        coef*=(i+u-1);
        coef/=i;
    }
    return sum>=k;
}
signed main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    reverse(a+1, a+n+1);
    int l=-1, r=1e18;
    while (l+1<r) {
        int mid=(l+r)/2;
        if (check(mid)) r=mid;
        else l=mid;
    }
    cout<<r;
    return 0;
}
