#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    vector<int> arr(n);
    for(int &i: arr) cin >> i;

    int q; cin >> q;

    int mn = -1;

    vector<pair<int,int>> qw(q);
    for(int i = 0; i < q; i++){
        int x; cin >> x;
        mn = max(mn, x);
        qw[i] = {x, i};
    }

    sort(qw.begin(), qw.end());

    vector<int> ans(q);
    vector<int> memo(1e6+5, -1);

    int j = -1, cans = -1;
    for(int i = 0; i < q; i++){
        int sum = 0;
        if(qw[i].first < mn + 500) {
            if(memo[qw[i].first]){
                ans[qw[i].second] = memo[qw[i].first];
                continue;
            }

            cans = 0;
            
            for(int a = 0; a < n; a++){
                if(arr[a] > qw[i].first){
                    ans[qw[i].second] = -1; cans = -1;
                    j = i;
                    break;
                }
                if(sum + arr[a] > qw[i].first){
                    sum = 0; cans++;
                }
                sum += arr[a];
            }

            ans[qw[i].second] = cans;

        }
        
        if(i <= j) {ans[qw[i].second] = cans; continue;}
        int t = qw[i].first;
        cans = 0;
        for(int a = 0; a < n; a++){
            if(arr[a] > t){
                ans[qw[i].second] = -1; cans = -1;
                j = i;
                break;
            }
            if(sum + arr[a] > t){
                sum = 0; cans++;
            }
            sum += arr[a];
        }


        if(cans == -1) continue;

        ans[qw[i].second] = cans;
        
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