#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

const int mxn = 1e5+5;

bool ok;

void upd(int ind, int val, vector<int> &bit){   //O(logn)
    while(ind<=bit.size()-1){
        bit[ind]=max(val, bit[ind]);
        ind+=ind&-ind;
    }
}
int sum(int ind, vector<int> &bit){         //O(logn)
    int ans=0;
    while(ind){
        ans=max(bit[ind],ans);    
        ind-=ind&-ind;    
    }
    return ans;
}

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first != b.first) return  b.first < a.first;
    else return a.second < b.second;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    int Xl, Yl, Xr, Yr; cin >> Xl >> Yl >> Xr >> Yr;

    bool ok = true;

    if(Xl > Xr) {swap(Xl, Xr); ok = !ok;}
    if(Yl > Yr) {swap(Yl, Yr); ok = !ok;}

    map<int,int> mp;
    vector<int> sarr(n);

    vector<pair<int,int>> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
        sarr[i] = arr[i].second;
    }


    int cnt = 1;
    sort(sarr.begin(), sarr.end());

    for(int i: sarr){
        mp[i] = cnt++;
    }

    vector<int> bit(cnt+1,0);

    sort(arr.begin(), arr.end());
    if(!ok) sort(arr.begin(), arr.end(), cmp);

    int ans = 0;

    for(int i = 0; i < n; i++){
        auto [x,y] = arr[i];
        if(x < Xl || y < Yl || y > Yr || x > Xr) continue;
        
        if(ok || !ok){
            int T = sum(mp[y], bit); T++;

            ans = max(ans, T);
            upd(mp[y], T, bit);
        }
        else{
            int T = sum(cnt-mp[y], bit); T++;

            ans = max(ans, T);
            upd(cnt-mp[y], T, bit);
        }
    }

    cout << ans << '\n';

    return 0;
}