#include<bits/stdc++.h>
#define ld long double
using namespace std;
ld a[6], k;
signed main() {
	for(int i=0;i<4;i++) cin>>a[i];
	cin>>k;
	sort(a,a+4);
	if(a[1]+a[2]+a[3]<=k*3) cout<<"infinite";
	else if(a[0]+a[1]+a[2]>k*3) cout<<"impossible";
	else printf("%.2Lf\n",k*3-a[1]-a[2]);
	
}


