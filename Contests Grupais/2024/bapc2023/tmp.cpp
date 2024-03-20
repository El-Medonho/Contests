#include "bits/stdc++.h"

using namespace std;

#define endl '\n'

typedef long long ll;

const int mxn = 1e5+5;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,m; cin >> n >> m;

    vector<string> arr(n);

    for(string &i: arr) cin >> i;

    vector<vector<int>> freq(m, vector<int>(26, 0));

    string ans = "";

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            freq[j][arr[i][j] - 'a']++;
        }
    }

    // cout << freq[0][2] << endl;;

    for(int i = 0; i < m; i++){
        pair<int,int> best = {-1,-1};

        for(int j = 0; j < 26; j++){
            if(freq[i][j] > best.first) best = {freq[i][j], j};
        }

        ans += 'a' + best.second;
    }

    cout << ans << endl;

    return 0;
}