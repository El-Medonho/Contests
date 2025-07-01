#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
const int mxn = 200 * 200 +5;
const int INF = 0x3f3f3f3f;
int dp[mxn][32][4];

int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n = 5;
    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }
    memset(dp, -INF, sizeof(dp));
    for(int i=0; i<=100; i++){
        for(int j=0; j<=100; j++){
            for(int k=0; k<4; k++){
                dp[101 * i + j][0][k] = 0;
            }
        }
    }
    int menor = INF;
    for(int mask = 1; mask < (1<<n); mask++){
        for(int k=0; k<n; k++){
            if(mask & (1<<k)){
                int nmask = mask ^ (1<<k);
                for(int i=0; i<=100; i++){
                    for(int j=0; j<=100; j++){
                        int d = abs(v[k].first  - i) + abs(v[k].second - j);
                        int pos = 101 * i + j;
                        int pri = -dp[pos][nmask][0] - i - j;
                        int seg = -dp[pos][nmask][1] - i + j;
                        int ter = -dp[pos][nmask][2] + i - j;
                        int qua = -dp[pos][nmask][3] + i + j;
                        
                        int maior = max({pri, seg, ter, qua});

                        if(mask == (1<<n)-1){
                            menor = min(menor, maior - d);
                        }

                        dp[pos][mask][0] = max(dp[pos][mask][0], maior - d + i + j);
                        dp[pos][mask][1] = max(dp[pos][mask][1], maior - d + i - j);
                        dp[pos][mask][2] = max(dp[pos][mask][2], maior - d - i + j);
                        dp[pos][mask][3] = max(dp[pos][mask][3], maior - d - i - j);
                    }
                }
            }
        }
    }
    cout << menor << endl;
    return 0;
}