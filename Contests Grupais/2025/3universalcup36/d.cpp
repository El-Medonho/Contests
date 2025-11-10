#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n+1);
        for(int& ai : a) {
            cin >> ai;
            ai--;
        }

        a.back()++;

        string ans;
        bool impossible = false;

        for(int i = 0; i < n; i++) {
            if(a[i] < 0) {
                impossible = true;
                break;
            }

            while(a[i] > 0) {
                a[i+1]--, a[i]--;
                ans.push_back('R');
                ans.push_back('L');
            }

            a[i+1]--;
            ans.push_back('R');
        }

        if(a[n] != 0) impossible = true;

        ans.insert(ans.end(), n, 'L');

        if(impossible) cout << "Impossible\n";
        else cout << ans << '\n';
    }
    return 0;
}