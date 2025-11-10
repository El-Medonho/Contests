#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;

    vector<int> p(n, 0), w(n, 1), ch(n, 0), arr(n), vis(n, 0), combo(n, 0), cms(0); cms.reserve(n);
    for(int i = 0; i < n; i++) p[i] = i;

    function<int(int)> ff = [&](int x){
        if(p[x] == x) return x;
        return p[x] = ff(p[x]);
    };

    function<void(int, int)> uu = [&](int x, int y){
        x = ff(x); y = ff(y);
        if(x == y) return;
        if(w[x] < w[y]) swap(x, y);
        p[y] = x;
        w[x] += w[y];
        return;
    };

    queue<int> qw;

    for(int i = 0; i < n; i++){
        cin >> arr[i]; arr[i]--;
        ch[arr[i]]++;
    }

    for(int i = 0; i < n; i++){
        if(ch[i] == 0) qw.push(i);
    }

    while(!qw.empty()){
        int cc = qw.front(); qw.pop();
        vis[cc] = 1;
        uu(cc, arr[cc]);
        if(combo[cc]+1 > combo[arr[cc]]) {
            cms.push_back(combo[arr[cc]]);
            combo[arr[cc]] = combo[cc]+1;
        } else cms.push_back(combo[cc]+1);
        ch[arr[cc]]--;
        if(ch[arr[cc]] == 0) qw.push(arr[cc]);
    }

    vector<pair<int,int>> ws(0); ws.reserve(n);
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        int ini = i, cc = i;
        int cnt = 0, mx = 0;
        do{
            vis[cc] = 1;
            cnt++;
            if(combo[cc] > mx){
                if(mx) cms.push_back(mx);
                mx = combo[cc];
            } else if(combo[cc]) cms.push_back(combo[cc]);
            uu(cc, arr[cc]);
            cc = arr[cc];
        } while(cc != ini);
        int repr = ff(i);
        ws.emplace_back(cnt, cnt + mx);
        cms.push_back(cnt+mx);
        // cout << cnt << ' ' << mx << endl;
    }
    int N = ws.size();
    sort(ws.begin(), ws.end());

    int i = 0, mv = 0;
    for(int v = 1; v <= n; v++){
        while(i < N && v > ws[i].second){
            i++;
        }
        if(i == N) break;
        mv = v;
        if(v < ws[i].first){
            cout << 1 << ' ';
            continue;
        } 
        cout << 0 << ' ';
    }

    for(int i = 0; i < N; i++) swap(ws[i].first, ws[i].second);

    sort(cms.rbegin(), cms.rend());

    i = 0; int sum = cms[i]; N = cms.size();
    for(int v = mv+1; v <= n; v++){
        while(i < N && v > sum){
            i++;
            assert(i < N);
            sum += cms[i];
        }
        cout << i << ' ';
    }
    cout << endl;


    return 0;
}