#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

vector<int> divs(int x){
    set<int> d;
    for(int i = 1; i * i <= x; i++) {
        if(x%i == 0){
            d.insert(i); d.insert(x/i);
        }
    }
    d.erase(1);
    vector<int> n(0);
    for(int x: d) n.push_back(x);

    return n;
}

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int mxx = 1e9; mxx--;

    int n; cin >> n;
    set<int> st;
    vector<int> arr(0);

    for(int i = 0; i < n; i++){
        int x; cin >> x; st.insert(x);
    }

    for(int x: st) arr.push_back(x);

    n = arr.size();

    if(arr.size() == 1){
        cout << 1 << ' ' << mxx << endl;
        return 0;
    }

    function<int(int)> ff = [&](int x){
        int resp = 3;
        if(x <= 1) return resp;

        set<int> mods;
        for(int cc: arr) mods.insert(cc%x);

        return (int)mods.size();
    };

    if(arr.size() == 2){
        if(arr[1] - arr[0] == 1){
            cout << 2 << ' ' << mxx << endl;
            return 0;
        }

        vector<int> d = divs(arr[1] - arr[0]);

        int resp1 = 0;

        for(int x: d) {
            if(ff(x) == 1) resp1++;
        }

        cout << 1 << ' ' << resp1 << endl;
        return 0;
    }

    int b = 2;

    for(int i = 2; i < n; i++){
        if(arr[b]- arr[b-2] > arr[i] - arr[i-2]) b = i;
    }

    pair<int,int> best = {-3, 0};
    int h1 = arr[b] - arr[b-1];

    set<int> d2;

    {
        vector<int> d = divs(h1);

        int resp1 = 0, resp2 = 0;

        for(int x: d) {
            if(ff(x) == 1) resp1++;
            else if(ff(x) == 2) {d2.insert(x); resp2++;}
        }

        if(resp1) best = max(best, {-1, resp1});
        if(resp2) best = max(best, {-2, resp2});
    }

    h1 = arr[b-1] - arr[b-2];

    {
        vector<int> d = divs(h1);

        int resp1 = 0, resp2 = 0;

        for(int x: d) {
            if(ff(x) == 1) resp1++;
            else if(ff(x) == 2) {d2.insert(x); resp2++;}
        }

        if(resp1) best = max(best, {-1, resp1});
        if(resp2) best = max(best, {-2, resp2});
    }

    h1 = arr[b] - arr[b-2];

    {
        vector<int> d = divs(h1);

        int resp1 = 0, resp2 = 0;

        for(int x: d) {
            if(ff(x) == 1) resp1++;
            else if(ff(x) == 2) {d2.insert(x); resp2++;}
        }

        if(resp1) best = max(best, {-1, resp1});
        if(resp2) best = max(best, {-2, resp2});
    }

    if(best.first == -2) best.second = d2.size();

    cout << -best.first << ' ' << best.second << endl;

    return 0;
}