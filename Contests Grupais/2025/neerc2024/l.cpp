#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

int dp1[101][1<<16][1<<3][2], dp2[101][1<<16][1<<3][2];

const int m = 998244353;

int sum(int a, int b) {
    if(a+b >= m) return a+b-m;
    return a+b;
}

signed solve(){
    
    int n, m, k;
    cin >> n >> m >> k;

    string sw;
    cin >> sw;
    reverse(sw.begin(), sw.end());

    int w = 0;
    for(int i = 0; i < k; i++) {
        if(sw[i] == '1') w += (1<<i);
    }

    for(int mask = 0; mask < (1<<k); mask++) {
        if(mask != w) dp1[k][0][mask][0] = 1;
        else dp1[k][0][mask][1] = 1;
    }

    for(int i = k+1; i <= n; i++) {
        for(int freq = 0; freq < (1<<(1<<(k+1))); freq++) {
            for(int mask = 0; mask < (1<<k); mask++) {
                int new_mask = (mask<<1) & ((1<<k)-1);
                int new_freq = freq | (1<<(mask<<1));
                dp1[i][new_freq][new_mask][1] = sum(dp1[i][new_freq][new_mask][1], dp1[i-1][freq][mask][1]);
                if(new_mask == w) dp1[i][new_freq][new_mask][1] = sum(dp1[i][new_freq][new_mask][1], dp1[i-1][freq][mask][0]);
                else dp1[i][new_freq][new_mask][0] = sum(dp1[i][new_freq][new_mask][0], dp1[i-1][freq][mask][0]);

                new_mask |= 1;
                new_freq = freq | (1<<((mask<<1)+1));
                dp1[i][new_freq][new_mask][1] = sum(dp1[i][new_freq][new_mask][1], dp1[i-1][freq][mask][1]);
                if(new_mask == w) dp1[i][new_freq][new_mask][1] = sum(dp1[i][new_freq][new_mask][1], dp1[i-1][freq][mask][0]);
                else dp1[i][new_freq][new_mask][0] = sum(dp1[i][new_freq][new_mask][0], dp1[i-1][freq][mask][0]);
            }
        }
    }

    for(int m1 = 0; m1 < (1<<k); m1++) {
        for(int freq = 0; freq < (1<<(1<<(k+1))); freq++) {
            if(m1 == w) {
                for(int m2 = 0; m2 < (1<<k); m2++) {
                    dp2[k][freq][m1][1] = sum(dp2[k][freq][m1][1], dp1[n][freq][m2][1]);
                }
            }else {
                for(int m2 = 0; m2 < (1<<k); m2++) {
                    dp2[k][freq][m1][0] = sum(dp2[k][freq][m1][0], dp1[n][freq][m2][1]);
                }
            }
        }
    }

    for(int i = k+1; i <= m; i++) {
        for(int freq = 0; freq < (1<<(1<<(k+1))); freq++) {
            for(int mask = 0; mask < (1<<k); mask++) {
                if(!(freq & (1<<(mask<<1)))) {
                    int new_mask = (mask<<1) & ((1<<k)-1);
                    dp2[i][freq][new_mask][1] = sum(dp2[i][freq][new_mask][1], dp2[i-1][freq][mask][1]);
                    if(new_mask == w) dp2[i][freq][new_mask][1] = sum(dp2[i][freq][new_mask][1], dp2[i-1][freq][mask][0]);
                    else dp2[i][freq][new_mask][0] = sum(dp2[i][freq][new_mask][0], dp2[i-1][freq][mask][0]);
                }

                if(!(freq & (1<<((mask<<1)+1)))) {
                    int new_mask = ((mask<<1)+1) & ((1<<k)-1);
                    dp2[i][freq][new_mask][1] = sum(dp2[i][freq][new_mask][1], dp2[i-1][freq][mask][1]);
                    if(new_mask == w) dp2[i][freq][new_mask][1] = sum(dp2[i][freq][new_mask][1], dp2[i-1][freq][mask][0]);
                    else dp2[i][freq][new_mask][0] = sum(dp2[i][freq][new_mask][0], dp2[i-1][freq][mask][0]);
                }
            }
        }
    }

    int ans = 0;

    for(int freq = 0; freq < (1<<(1<<(k+1))); freq++) {
        for(int mask = 0; mask < (1<<k); mask++) {
            ans = sum(ans, dp2[m][freq][mask][1]);
        }
    }

    cout << ans << '\n';

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t = 1;

    while(t--){
        solve();
    }


    return 0;
}