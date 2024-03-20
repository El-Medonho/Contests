// ⢸⣿⣿⣿⣿⠃⠄⢀⣴⡾⠃⠄⠄⠄⠄⠄⠈⠺⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⣿⣶⣤⡀⠄
// ⢸⣿⣿⣿⡟⢀⣴⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣿⣿⣿⣿⣿⣿⣿⣷
// ⢸⣿⣿⠟⣴⣿⡿⡟⡼⢹⣷⢲⡶⣖⣾⣶⢄⠄⠄⠄⠄⠄⢀⣼⣿⢿⣿⣿⣿⣿⣿⣿⣿
// ⢸⣿⢫⣾⣿⡟⣾⡸⢠⡿⢳⡿⠍⣼⣿⢏⣿⣷⢄⡀⠄⢠⣾⢻⣿⣸⣿⣿⣿⣿⣿⣿⣿
// ⡿⣡⣿⣿⡟⡼⡁⠁⣰⠂⡾⠉⢨⣿⠃⣿⡿⠍⣾⣟⢤⣿⢇⣿⢇⣿⣿⢿⣿⣿⣿⣿⣿
// ⣱⣿⣿⡟⡐⣰⣧⡷⣿⣴⣧⣤⣼⣯⢸⡿⠁⣰⠟⢀⣼⠏⣲⠏⢸⣿⡟⣿⣿⣿⣿⣿⣿
// ⣿⣿⡟⠁⠄⠟⣁⠄⢡⣿⣿⣿⣿⣿⣿⣦⣼⢟⢀⡼⠃⡹⠃⡀⢸⡿⢸⣿⣿⣿⣿⣿⡟
// ⣿⣿⠃⠄⢀⣾⠋⠓⢰⣿⣿⣿⣿⣿⣿⠿⣿⣿⣾⣅⢔⣕⡇⡇⡼⢁⣿⣿⣿⣿⣿⣿⢣
// ⣿⡟⠄⠄⣾⣇⠷⣢⣿⣿⣿⣿⣿⣿⣿⣭⣀⡈⠙⢿⣿⣿⡇⡧⢁⣾⣿⣿⣿⣿⣿⢏⣾
// ⣿⡇⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢻⠇⠄⠄⢿⣿⡇⢡⣾⣿⣿⣿⣿⣿⣏⣼⣿
// ⣿⣷⢰⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⢰⣧⣀⡄⢀⠘⡿⣰⣿⣿⣿⣿⣿⣿⠟⣼⣿⣿
// ⢹⣿⢸⣿⣿⠟⠻⢿⣿⣿⣿⣿⣿⣿⣿⣶⣭⣉⣤⣿⢈⣼⣿⣿⣿⣿⣿⣿⠏⣾⣹⣿⣿
// ⢸⠇⡜⣿⡟⠄⠄⠄⠈⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟⣱⣻⣿⣿⣿⣿⣿⠟⠁⢳⠃⣿⣿⣿
// ⠄⣰⡗⠹⣿⣄⠄⠄⠄⢀⣿⣿⣿⣿⣿⣿⠟⣅⣥⣿⣿⣿⣿⠿⠋⠄⠄⣾⡌⢠⣿⡿⠃
// ⠜⠋⢠⣷⢻⣿⣿⣶⣾⣿⣿⣿⣿⠿⣛⣥⣾⣿⠿⠟⠛⠉⠄⠄

#include "bits/stdc++.h"

using namespace std;

#define f first
#define s second
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
typedef long long ll;

void upd(int ind, ll val, vector<ll> &bit){   //O(logn)
    while(ind<=bit.size()-1){
        bit[ind]=max(val, bit[ind]);
        ind+=ind&-ind;
    }
}
ll sum(int ind, vector<ll> &bit){         //O(logn)
    ll ans=-1;
    while(ind){
        ans=max(bit[ind], ans);    
        ind-=ind&-ind;    
    }
    return ans;
}


signed main(){
    fastio;

    int n; cin >> n;

    vector<int> show(n);
    vector<pair< pair<int,int>, pair<int,int>>> arr(0); 

    for(int i = 0; i < n; i++){
        cin >> show[i];

        for(int j = 0; j < show[i]; j++){
            int a,b,c; cin >> a >> b >> c;
            arr.push_back(make_pair( make_pair(a,b), make_pair(c,i) ));
        }
    }

    sort(arr.begin(), arr.end());

    int m = arr.size();

    vector<vector<int>> dp(m, vector<int>((1<<n), -1));
    vector<int> last(m, -1), mx((1<<n), -1); mx[0] = 0;
    int ans = -1;

    for(int i = 0; i < m; i++){
        dp[i][0] = 0;
        pair<int,int> h = {1e8,-1};
        for(int j = i; j < m; j++){
            if(arr[j].f.f < h.f && arr[j].f.f >= arr[i].f.s) h = {arr[j].f.f, j};
        }

        last[i] = h.s;
    }

    for(int i = 0; i < m; i++){
        int a = arr[i].f.f, b = arr[i].f.s, c = arr[i].s.f, k = arr[i].s.s;
        // if(last[i] != -1) dp[i] = dp[last[i]];
        for(int j = (1<<n)-1; j > -1; j--){
            if(i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(dp[i][j] == -1) continue;
            if(last[i] != -1) dp[last[i]] [j | (1<<k)] = max(dp[i][j] + c, dp[last[i]] [j | (1<<k)] );
            int gg = (1<<n)-1, ggg = j | (1<<k);
            if( (j | (1<<k)) == ((1<<n)-1) ) ans = max(ans, dp[i][j] + c);
        }
    }

    cout << ans << '\n';

    return 0;
}