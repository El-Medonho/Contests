 #include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> x(n);
    for(int& xi : x) cin >> xi;

    ll open = 0, closed = 0;

    for(int xi : x) {
        if(open+closed == 0 && xi != 0) {
            open = xi;
            closed = 2;
        }else if(xi <= open) {
            closed += open-xi;
            open = xi;
        }else {
            open = xi;
            closed++;
        }
    }

    cout << open+closed << '\n';

    return 0;
} 