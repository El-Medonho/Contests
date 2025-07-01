#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define endl '\n'

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    map<int,vector<int>> mp;

    vector<pair<int,int>> ans(0);

    set<int> b2, base;

    int n; cin >> n;

    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;

        if(b == 1){
            base.insert(a);
            continue;
        }

        if(b == 2) {
            b2.insert(a);
            continue;
        }

        mp[a].push_back(b);
    }

    bool ok = true;

    if((*mp.begin()).first == 1) ok = false;

    int l = 0;

    for(auto[x, y]: mp){
        if(!ok){
            if(x > l+1){
                ans.emplace_back(l+1, 2);
                if(b2.find(l+1) != b2.end()) b2.erase(l+1);
                l = l+1;
                ok = true;
            }
            else{
                ans.emplace_back(l+1, 2);
                if(b2.find(l+1) != b2.end()) b2.erase(l+1);
                sort(y.begin(), y.end());
                for(int cc: y){
                    ans.emplace_back(x, cc);
                }
                l = x;
                continue;
            }    
        }

        while(!b2.empty() && (*(b2.begin())) < x-1){
            ans.emplace_back((*b2.begin()), 2);
            b2.erase(b2.begin());
        }

        if(l != x-1) {
            ans.emplace_back(x-1, 2);
            if(b2.find(x-1) != b2.end()) b2.erase(x-1);
        }

        sort(y.rbegin(), y.rend());
        for(int cc: y){
            ans.emplace_back(x, cc);
        }

        ans.emplace_back(x, 2);
        if(b2.find(x) != b2.end()) b2.erase(x);

        l = x;
    }
    if(!ok){
        ans.emplace_back(l+1, 2);
        if(b2.find(l+1) != b2.end()) b2.erase(l+1);
    }

    while(!b2.empty()){
        ans.emplace_back((*b2.begin()), 2);
        l = (*b2.begin());
        b2.erase(b2.begin());
    }
    
    if(ans.size() == 3*n && ans.back().second == 2){
        int h = ans.back().first;
        ans.pop_back();
        ans.emplace_back(h, 1);
    }

    if(ans.empty()){
        ans.emplace_back(1,2);
    }

    if(base.empty() && ans.size() < 3*n){
        ans.emplace_back(l, 1);
    }
    else if(ans.size() < 3*n){
        for(auto it = base.rbegin(); it != base.rend(); it++){
            int cc = *it;
            ans.emplace_back(cc, 1);
        }
    }

    assert(ans.size() <= 3*n);

    cout << ans.size() << '\n';

    for(auto[x, y]: ans){
        cout << x << ' ' << y << '\n';
    }
    

    return 0;
}