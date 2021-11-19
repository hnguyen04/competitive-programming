#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int a, b, n, m, k, tt;
    string s, s1, s2;
    cin >> tt;
    for (int t = 0; t < tt; t++){
        cin >> n;
        cin >> s;
        s1 = s2 = s;
        a = 0;
        for (int i = 0; i < n; i++) if (s[i] == '0') a++;
        if (s[0] == '0' || s[n-1] == '0' || a%2 == 1) cout << "NO\n";
        else {
            cout << "YES\n";
            a = n-a;
            k = a/2;
            for (int i = 0; i < n; i++){
                if (s[i] == '1'){
                    if (k > 0) s1[i] = s2[i] = '(', k--;
                    else s1[i] = s2[i] = ')';
                }
            }
            for (int i = 0; i < n; i++){
                if (s[i] == '0'){
                    if (k%2 == 0) s1[i] = '(', s2[i] = ')';
                    else s1[i] = ')', s2[i] = '(';
                    k++;
                }
            }
            cout << s1 << "\n" << s2 << "\n";
        }
    }
}
