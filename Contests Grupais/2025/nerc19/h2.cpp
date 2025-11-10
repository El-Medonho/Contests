#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    vector<int> arr(n);
    int mn = -1;
    for(int &i: arr) {
        cin >> i;
        mn = max(mn, i);
    }
    int q; cin >> q;



    vector<pair<int,int>> qw(q);
    for(int i = 0; i < q; i++){
        int x; cin >> x;
        qw[i] = {x, i};
    }

    sort(qw.begin(), qw.end());

    vector<int> ans(q);
    vector<int> memo(1e6+5, 0);

    int j = -1, cans = -1;
    for(int i = 0; i < q; i++){
        if(qw[i].first < mn) {
            ans[qw[i].second] = -1;
            continue;
        }
        if(i <= j) {ans[qw[i].second] = cans; continue;}
        if(memo[qw[i].first]) {
            ans[qw[i].second] = memo[qw[i].first];
            continue;
        }

        int t = qw[i].first;
        cans = 0;
        int sum = 0;
        for(int a = 0; a < n; a++){
            if(sum + arr[a] > t){
                sum = 0; cans++;
            }
            sum += arr[a];
        }

        if(cans == -1) continue;

        ans[qw[i].second] = cans;
        memo[qw[i].first] = cans;
        if(qw[i].first < mn+500) continue;
        
        int l = i, r = q-1;

        while(l <= r){
            int md = (l+r)/2; int tt = qw[md].first;

            sum = 0; int cnt = 0;
            for(int a = 0; a < n; a++){
                if(sum + arr[a] > tt){
                    sum = 0; cnt++;
                }
                sum += arr[a];
            }

            if(cnt != cans){
                r = md-1;
            } else{
                j = md;
                l = md+1;
            }
        }
    }
    for(int i: ans){
        i++;
        if(i == 0) cout << "Impossible\n";
        else cout << i << endl;
    }

    return 0;
}