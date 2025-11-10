#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
typedef long long ll;

const int sz = 180;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n,k; cin >> n >> k;

    int num = (n+sz-1)/sz;
    
    vector<map<int,int>> maps(num);
    vector<int> offset(num, 0);
    vector<bool> will_upd(num, 0);
    vector<map<int,int>> upd_map(num), inv_upd_map(num), upd_qtt(num);
    vector<int> arr(n);
    
    function<int(int,int)> ff = [&](int ind, int x){
        if(inv_upd_map[ind][x] != x) return inv_upd_map[ind][x] = ff(ind, inv_upd_map[ind][x]);
        return x;
    };

    auto uu = [&](int x, int y, int ind){
        int bx = x;
        x = ff(ind, x); y = ff(ind, y);
        
        if(x == y) return;

        upd_map[ind][y] = bx;
        upd_map[ind][x] = bx;

        if(upd_qtt[ind][x] < upd_qtt[ind][y]) swap(x, y);

        upd_qtt[ind][x] += upd_qtt[ind][y];
        inv_upd_map[ind][y] = x;
    };

    auto upd_sec = [&](int ind){
        for(int i = ind*sz; i < n && i/sz == ind; i++){
            if(maps[ind].find(arr[i]) == maps[ind].end()) {
                arr[i] = upd_map[ind][ff(ind, arr[i])];
            }
        }

        upd_map[ind].clear();
        upd_qtt[ind].clear();
        inv_upd_map[ind].clear();

        will_upd[ind] = 0;
    };


    for(int i = 0; i < n; i++){
        cin >> arr[i];
        maps[i/sz][arr[i]]++;
    }

    while(k--){
        char c; cin >> c;
        int l,r; cin >> l >> r; l--; r--;

        if(c == 'A'){
            while(l <= r){
                if(l/sz == r/sz || l%sz != 0){
                    if(will_upd[l/sz]) upd_sec(l/sz);
                    int cc = arr[l];
                    maps[l/sz][cc]--;
                    if(maps[l/sz][cc] == 0) maps[l/sz].erase(cc);
                    maps[l/sz][cc+1]++;
                    arr[l]++;
                    l++;
                }
                else{
                    offset[l/sz]++;
                    l+=sz;
                }
            }
        }

        if(c == 'R'){
            int b = 0;
            for(int i = 0; i < num; i++){
                int h = (*maps[i].rbegin()).first;
                h += offset[i];
                b = max(b, h);
            }

            if(b == 0) continue;

            while(l <= r){
                if(l/sz == r/sz || l%sz != 0){
                    if(will_upd[l/sz]) upd_sec(l/sz);
                    if(arr[l] + offset[l/sz] != b) { l++; continue;}
                    int cc = arr[l];
                    maps[l/sz][cc]--;
                    if(maps[l/sz][cc] == 0) maps[l/sz].erase(cc);
                    maps[l/sz][-offset[l/sz]]++;
                    arr[l] = -offset[l/sz];
                    l++;
                }
                else{
                    if(maps[l/sz].find(b-offset[l/sz]) == maps[l/sz].end()) { l+=sz; continue;}
                    maps[l/sz][-offset[l/sz]] += maps[l/sz][b-offset[l/sz]];
                    
                    maps[l/sz].erase(b-offset[l/sz]);
                    will_upd[l/sz] = true;


                    if(inv_upd_map[l/sz].find(b-offset[l/sz]) == inv_upd_map[l/sz].end()) {
                        inv_upd_map[l/sz][b-offset[l/sz]] = b-offset[l/sz];
                        upd_qtt[l/sz][b-offset[l/sz]] = 1;
                    }
                    if(inv_upd_map[l/sz].find(-offset[l/sz]) == inv_upd_map[l/sz].end()) {
                        inv_upd_map[l/sz][-offset[l/sz]] = -offset[l/sz];
                        upd_qtt[l/sz][-offset[l/sz]] = 1;
                    }
                    uu(-offset[l/sz], b-offset[l/sz], l/sz);
                
                    l+=sz;
                }
            }
        }

        if(c == 'Q'){
            int b = 0;
            while(l <= r){
                if(l/sz == r/sz || l%sz != 0){
                    if(will_upd[l/sz]) upd_sec(l/sz);
                    b = max(b, arr[l] + offset[l/sz]);
                    l++;
                }
                else{
                    int h = (*maps[l/sz].rbegin()).first;
                    h += offset[l/sz];
                    b = max(b, h);
                    l += sz; 
                }
            }

            cout << b << endl;
        }
    }

    return 0;
}